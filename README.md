# mace-makefile-project
Mace是小米发布的移动端深度学习加速库。但是现在不支持离线编译和arm-linux交叉编译，为了快速验证Mace在嵌入式端的性能，故把MACE的源码和依赖提出来，搞了一个
可以使用MakeFile进行交叉编译libmace.a的工程，省去了Bazel编译的麻烦。＜/br＞

1.如果你要在3519上运行mace，那么请依次执行以下命令(protobuf的库已经编好了) ＜/br＞
  cd mace;＜/br＞
  make clean;＜/br＞
  make;＜/br＞
  cp libmace.a ＜/br＞
  ../library/mace ＜/br＞
  cd unit_test ＜/br＞
  make clean;make ＜/br＞
  ./demo ＜/br＞
备注：如何你的交叉编译链不是arm-hisiv600-linux-,请在mace文件夹和unit_test文件夹的的MAKEFILE文件中修改编译链路径。＜/br＞

2.如果你要在其他嵌入式平台上运行，请按照以下步骤编译 ＜/br＞
(1).使用对应的交叉编译链先编译好protobuf3.4.0,为了省去下载的麻烦，我这里提供protobuf3.4.0的源码。＜/br＞
(2).https://blog.csdn.net/adrian169/article/details/9051839,可以按照这个链接方法来编译＜/br＞
(3).把编译好的libprotoc.a和libprotobuf.a和libproto-lite.a拷贝到library/mace/目录下 ＜/br＞
(4).接下来按照1方法运行 ＜/br＞
    cd mace; ＜/br＞
    make clean; ＜/br＞
    make; ＜/br＞
    cp libmace.a ＜/br＞
    ../library/mace ＜/br＞
    cd unit_test ＜/br＞
    make clean;make ＜/br＞
    ./demo ＜/br＞
    
 3.通过unit_test.cpp中可以看出，本工程现在只提供了mobilenetv1的测试。运行mace需要的权重文件和网络配置文件分别为mobilenetv1_v1.data和mobilenetv1.proto ＜/br＞
 4.如果你需要测试其他网络，需要把caffe或者tensorflow模型转换成*.data和*.pb文件，具体怎么做请参考https://mace.readthedocs.io/en/latest/getting_started/how_to_build.html
   模型转换ok之后，请修改unit_test.cpp中对应代码。
