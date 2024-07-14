#### demo

测试基础的`CMAKE`语法：
* `cmake_minimum_required`：指定`CMAKE`的最低版本要求
* `project`：指定项目名称
* `set`：设置变量
* `message`：打印信息
* `aux_source_directory`：查找指定目录下的所有源文件
* `add_executable`：指定生成可执行文件
* `CMAKE_RUNTIME_OUTPUT_DIRECTORY`：指定可执行文件输出目录
* `CMAKE_CXX_STANDARD`：指定C++标准
* `CMAKE_CXX_FLAGS`：指定C++编译选项
* `CMAKE_SOURCE_DIR`：指定项目根目录
* `CMAKE_CURRENT_SOURCE_DIR`：指定当前目录
* `CMAKE_CURRENT_BINARY_DIR`：指定当前编译目录

编译：
```shell
mkdir build
cd build
cmake ..
make
../bin/app
```
