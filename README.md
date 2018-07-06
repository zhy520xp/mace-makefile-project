# mace-makefile-project
Mace是小米发布的移动端深度学习加速库。但是现在不支持离线编译和arm-linux交叉编译，为了快速验证Mace在嵌入式端的性能，故把MACE的源码和依赖提出来，搞了一个可以使用MakeFile进行交叉编译libmace.a的工程，省去了Bazel编译的麻烦。 本工程主要针对3559A，3536，rk3288（预装ubuntu系统），rk3399（预装ubuntu系统）这类带GPU的嵌入式SOC。 

1.如果你要在3559A上使用CPU来运行mace框架，那么请依次执行以下命令(3559a平台上的protobuf的库已经编好了)  
  cd mace;  
  vim Makefike  
  将PLATFORM改为CPU  
  make clean;  
  make;  
  cp libmace.a ../library/mace_cpu  
  cd unit_test_cpu  
  make clean;make   
  ./demo   
备注：如何你的交叉编译链不是aarch64-himix100-linux-,请在mace文件夹和unit_test文件夹的的MAKEFILE文件中修改编译链路径。  

2.如果你要在3559A上使用GPU来运行mace框架，那么请依次执行以下命令：  
  cd mace;  
  vim Makefile;  
  将PLATFORM改为GPU  
  make clean;make  
  cp libmace.a ../library/mace_gpu  
  cd unit_test_gpu  
  make clean;make  
  ./demo  

2.如果你要在其他嵌入式平台上运行，请按照以下步骤编译  
(1).使用对应的交叉编译链先编译好protobuf3.4.0,https://cnbj1.fds.api.xiaomi.com/mace/third-party/protobuf/protobuf-3.4.0.zip。  
(2).https://blog.csdn.net/adrian169/article/details/9051839  
    可以按照这个链接方法来编译  
(3).把编译好的libprotoc.a和libprotobuf.a和libproto-lite.a拷贝到library/mace/目录下   
(4).如果是使用CPU来运行mace，接下来按照1方法运行 
(5).如果是使用GPU来运行mace，参考2，只是在运行demo前，需要先把opencl的库libopencl.so，libmali.so放到opencl_library下。  
    特别需要注意的是，嵌入式端运行GPU需要保证GPU的驱动加载好了，不然运行demo的时候会“Kernel module may not have been loaded”的错误。
    如果GPU运行时除了libopencl.so，libmali.so之外还有其他动态库，请在mace/core/runtime/opencl/opencl_wrapper.cc的278行加上库路径即可。  
 
 3.通过unit_test.cpp中可以看出，本工程现在只提供了mobilenetv1的测试。运行mace需要的权重文件和网络配置文件分别为mobilenetv1_v1.data和mobilenetv1.proto。特别需要注意的是部署在gpu上的model和部署到cpu上的model是不能混用的。主要原因是因为gpu模型运算是f16，cpu是f32。
 
 4.如果你需要测试其他网络，需要把caffe或者tensorflow模型转换成*.data和*.pb文件，具体怎么做请参考https://mace.readthedocs.io/en/latest/getting_started/how_to_build.html  
   模型转换ok之后，请修改unit_test.cpp中对应代码。
