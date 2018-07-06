CXX = aarch64-himix100-linux-g++
CC = aarch64-himix100-linux-gcc
AR = aarch64-himix100-linux-ar cqs

TOP_DIR = ..

PLATFORM = GPU

TARGET_LIB = libmace.a

ifeq ($(PLATFORM),GPU)
CXX_SOURCE += $(TOP_DIR)/mace/codegen/opencl/opencl_encrypt_program.cc
CXX_SOURCE += $(TOP_DIR)/mace/codegen/tuning/tuning_params.cc
CXX_SOURCE += $(TOP_DIR)/mace/codegen/version/version.cc
endif

####################proto source file###################
CXX_SOURCE += $(TOP_DIR)/mace/proto/mace.pb.cc

####################utils source file################### 
CXX_SOURCE += $(TOP_DIR)/mace/utils/logging.cc
CXX_SOURCE += $(TOP_DIR)/mace/utils/string_util.cc
CXX_SOURCE += $(TOP_DIR)/mace/utils/tuner_production.cc
#CXX_SOURCE += $(TOP_DIR)/mace/utils/tuner_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/utils/tuner_development.cc

####################kernels arm source file################### 
CXX_SOURCE += $(TOP_DIR)/mace/kernels/conv_pool_2d_util.cc
#CXX_SOURCE += $(TOP_DIR)/mace/kernels/gemm_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/gemm.cc
#CXX_SOURCE += $(TOP_DIR)/mace/kernels/matmul_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/kernels/memory_benchmark.cc

CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/conv_2d_neon_1x1.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/conv_2d_neon_1x7.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/conv_2d_neon_1x15.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/conv_2d_neon_3x3.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/conv_2d_neon_5x5.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/conv_2d_neon_7x7.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/conv_2d_neon_7x1.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/conv_2d_neon_15x1.cc
#CXX_SOURCE += $(TOP_DIR)/source/kernels/arm/conv_winograd_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/conv_winograd.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/arm/depthwise_conv2d_neon_3x3.cc

####################kernels opencl source file################### 
ifeq ($(PLATFORM),GPU)
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/activation.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/addn.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/batch_norm.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/bias_add.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/buffer_to_image.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/channel_shuffle.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/concat.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/conv_2d_1x1.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/conv_2d_3x3.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/conv_2d_general.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/conv_2d.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/deconv_2d_opencl.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/depth_to_space.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/depthwise_conv.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/eltwise.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/fully_connected.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/helper.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/image_to_buffer.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/matmul.cc
#CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/out_of_range_check_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/pad.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/pooling.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/reduce_mean_opencl.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/resize_bilinear.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/slice.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/softmax.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/space_to_batch.cc
CXX_SOURCE += $(TOP_DIR)/mace/kernels/opencl/winograd_transform.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/buffer_to_image.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/image_to_buffer.cc
endif

####################ops source file################### 
#CXX_SOURCE += $(TOP_DIR)/mace/ops/activation_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/activation_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/activation.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/addn_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/addn_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/addn.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/batch_norm_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/batch_norm_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/batch_norm.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/batch_to_space_benchmark.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/batch_to_space.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/bias_add_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/bias_add_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/bias_add.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/buffer_to_image_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/buffer_to_image_test.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/cast_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/cast.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/channel_shuffle_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/channel_shuffle_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/channel_shuffle.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/concat_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/concat_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/concat.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/conv_2d_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/conv_2d_tesst.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/conv_2d.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/core_test.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/deconv_2d_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/deconv_2d_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/deconv_2d.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/depth_to_space_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/depth_to_space_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/depth_to_space.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/depthwise_conv2d_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/depthwise_conv2d_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/depthwise_conv2d.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/eltwise_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/eltwise_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/eltwise.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/folded_batch_norm_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/folded_batch_norm.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/fully_connected_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/fully_connected_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/fully_connected.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/gather_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/gather_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/gather.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/identity_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/identity.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/local_response_norm_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/local_respons_norm_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/local_response_norm.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/matmul_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/matmul_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/matmul.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/pad_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/pad_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/pad.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/pooling_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/pooling_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/pooling.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/proposal_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/proposal.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/quantize_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/quantize.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/reduce_mean_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/reduce_mean_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/reduce_mean.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/reshape_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/reshape.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/resize_bilinear_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/resize_bilinear_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/resize_bilinear.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/shape_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/shape.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/slice_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/slice_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/slice.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/softmax_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/softmax_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/softmax.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/space_to_batch_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/space_to_batch_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/space_to_batch.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/space_to_depth_benchmark.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/space_to_depth.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/squeeze_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/squeeze.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/stack_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/stack.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/strided_slice_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/strided_slice.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/transpose_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/transpose_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/transpose.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/winograd_convolution_benchmark.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/winograd_convolution_test.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/winograd_inverse_transform.cc
#CXX_SOURCE += $(TOP_DIR)/mace/ops/winograd_transform_benchmark.cc
CXX_SOURCE += $(TOP_DIR)/mace/ops/winograd_transform.cc
####################core source file###################

ifeq ($(PLATFORM),CPU)
CXX_SOURCE += $(TOP_DIR)/mace/core/runtime/cpu/cpu_runtime.cc
endif

ifeq ($(PLATFORM),GPU)
CXX_SOURCE += $(TOP_DIR)/mace/core/runtime/opencl/opencl_allocator.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/runtime/opencl/opencl_runtime.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/runtime/opencl/opencl_wrapper.cc
endif

CXX_SOURCE += $(TOP_DIR)/mace/core/allocator.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/arg_helper.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/file_storage.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/mace_runtime.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/mace.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/net.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/operator.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/runtime_failure_mock.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/types.cc
CXX_SOURCE += $(TOP_DIR)/mace/core/workspace.cc
####################head file###################
DEP_INC_DIR += -I$(TOP_DIR)
DEP_INC_DIR += -I$(TOP_DIR)/include/protobuf3.4.0
DEP_INC_DIR += -I$(TOP_DIR)/include
DEP_INC_DIR += -I$(TOP_DIR)/include/opencl_clhpp
DEP_INC_DIR += -I$(TOP_DIR)/include/opencl20
DEP_INC_DIR += -I$(TOP_DIR)/mace
DEP_INC_DIR += -I$(TOP_DIR)/mace/publics 

OBJ_CPP := $(patsubst %.cc, %.o, $(CXX_SOURCE))
OBJ_C := $(patsubst %.c, %.o, $(C_SOURCE))

DEFINE_MACRO := 
ifeq ($(PLATFORM),CPU)
CPPFLAGS := -O3 -std=c++11 -fpermissive -DMACE_ENABLE_NEON -DMACE_ENABLE_OPENMP
endif

ifeq ($(PLATFORM),GPU)
CPPFLAGS := -O3 -std=c++11 -fpermissive -DMACE_ENABLE_OPENCL
endif

CFLAGS := -Wall -O3
CPPFLAGS += $(DEP_INC_DIR) $(DEFINE_MACRO) 
CFLAGS += $(DEP_INC_DIR) $(DEFINE_MACRO) 

#$(TARGET_SHARED_LIB):$(OBJ_CPP) $(OBJ_C)
#	$(CXX) -o $@ $^ $(LDFLAGS)

$(TARGET_LIB):$(OBJ_CPP) $(OBJ_C)
	$(AR) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -o $@ -c $< 

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	rm -rf $(OBJ_CPP) $(OBJ_C) $(TARGET_LIB)
