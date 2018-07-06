#include <stdio.h>
#include <vector>
#include <sys/time.h>
#include <fstream>
#include <cmath>
#include <numeric>
#include <iostream>
#include <mace.h>
#include <mace_runtime.h>

static bool ReadBinaryFile(std::vector<unsigned char> *data,
                           const std::string &filename) {
  std::ifstream ifs(filename, std::ios::in | std::ios::binary);
  if (!ifs.is_open()) {
    return false;
  }
  ifs.seekg(0, ifs.end);
  size_t length = ifs.tellg();
  ifs.seekg(0, ifs.beg);

  data->reserve(length);
  data->insert(data->begin(), std::istreambuf_iterator<char>(ifs),
               std::istreambuf_iterator<char>());
  if (ifs.fail()) {
    return false;
  }
  ifs.close();

  return true;
}

int main(int argc, char** argv)
{
	// config runtime
	//mace::SetOpenMPThreadPolicy(-1,static_cast<CPUAffinityPolicy >(1));
	mace::DeviceType device_type = mace::GPU;//CPU = 0, GPU = 2, HEXAGON = 3

	if (device_type == mace::DeviceType::GPU) 
	{
		mace::SetGPUHints(
			static_cast<mace::GPUPerfHint>(3),
			static_cast<mace::GPUPriorityHint>(3));
	}
	
	if (device_type == mace::DeviceType::GPU) 
	{
		std::vector<std::string> opencl_binary_paths = {"./opencl_binary"};
		//mace::SetOpenCLBinaryPaths(opencl_binary_paths);
	}

	//1.read pb file
	std::vector<unsigned char> model_pb_data;
    if (!ReadBinaryFile(&model_pb_data, "mobilenet_v1.pb")) 
    {
		printf("=====>>>>Failed to read pb file!\n");
		return 0;
    }
	//2.create MaceEngine
	std::shared_ptr<mace::MaceEngine> engine;
    mace::MaceStatus create_engine_status;
	std::vector<std::string> input_nodes;
	input_nodes.push_back(std::string("input"));
	std::vector<std::string> output_nodes;
	output_nodes.push_back(std::string("MobilenetV1/Predictions/Reshape_1"));
	std::cout << "=====>>>>>start to CreateMaceEngineFromProto" << "\n";
    create_engine_status = CreateMaceEngineFromProto(model_pb_data,std::string("mobilenet_v1.data"),input_nodes
	,output_nodes,device_type,&engine);
	if (create_engine_status != mace::MaceStatus::MACE_SUCCESS) 
	{
    	std::cout << "Create engine error, please check the arguments";
		return 0;
  	}
	std::cout << "=====>>>>>end to CreateMaceEngineFromProto" << "\n";
	//3.load input data
	std::vector<int64_t> input_shapes = {1,224,224,3};
	int64_t input_size =std::accumulate(input_shapes.begin(), input_shapes.end(), 1,std::multiplies<int64_t>());
	auto buffer_in = std::shared_ptr<float>(new float[input_size],std::default_delete<float[]>());
	
	std::ifstream in_file("dog.npy",std::ios::in | std::ios::binary);
    if (in_file.is_open()) 
	{
      in_file.read(reinterpret_cast<char *>(buffer_in.get()),input_size * sizeof(float));
      in_file.close();
    } else 
	{
      std::cout << "Open input file failed";
      return -1;
    } 
	std::map<std::string, mace::MaceTensor> inputs;
	inputs["input"] = mace::MaceTensor(input_shapes, buffer_in);
	
	//4.output buffer
	std::vector<int64_t> output_shapes = {1,1001};
	 int64_t output_size = std::accumulate(output_shapes.begin(), output_shapes.end(), 1,std::multiplies<int64_t>());
    auto buffer_out = std::shared_ptr<float>(new float[output_size],std::default_delete<float[]>());
	std::map<std::string, mace::MaceTensor> outputs;
    outputs["MobilenetV1/Predictions/Reshape_1"] = mace::MaceTensor(output_shapes, buffer_out);

	//run Model
	struct timeval tm_before,tm_after;
	gettimeofday(&tm_before,NULL);
    engine->Run(inputs, &outputs);
	gettimeofday(&tm_after,NULL);
	printf("=====>>>>>Warm up Run Model spend time:%d ms\n",(tm_after.tv_sec -tm_before.tv_sec)*1000 + (tm_after.tv_usec - tm_before.tv_usec)/1000);
	
	for (int i = 0; i < 1; ++i) 
	{
		gettimeofday(&tm_before,NULL);
		engine->Run(inputs, &outputs);
		gettimeofday(&tm_after,NULL);
		printf("=====>>>>>Normal Run Model spend time:%d ms\n",(tm_after.tv_sec -tm_before.tv_sec)*1000 + (tm_after.tv_usec - tm_before.tv_usec)/1000);
	}
	
	//write output data to file
    std::string output_name = "mace.out";
    std::ofstream out_file(output_name, std::ios::binary);
    output_size = std::accumulate(output_shapes.begin(), output_shapes.end(), 1,std::multiplies<int64_t>());
	float *ptr = outputs["MobilenetV1/Predictions/Reshape_1"].data().get();
	for(int i=0;i<output_size;i++)
	{
		if(ptr[i] > 0.1)
		{
			printf("%f ,",ptr[i]);
		}	
	}
	printf("\n");
    out_file.write(reinterpret_cast<char *>(outputs["MobilenetV1/Predictions/Reshape_1"].data().get()),output_size * sizeof(float));
    out_file.flush();
    out_file.close();

	return 0;
}