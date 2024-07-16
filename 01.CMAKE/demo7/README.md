#### demo7

测试基本的`CMAKE`命令：
* `include`：添加外部宏
* `APP_VERSION_MAJOR`、`APP_VERSION_MINOR`：`APP`版本号
* `InstallRequiredSystemLibraries`：安装必需的系统库
* `CPACK_XXX`：`CPACK`相关参数


构建：
```shell
☁  build [main] ⚡  ../bin/app     
../bin/app Version 1.0
Usage: ../bin/app base exp


# test CPACK
☁  build [main] ⚡  cmake ..
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Looking for pow
-- Looking for pow - not found
/home/zhaoyang/.local/usr/
-- Configuring done (3.4s)
-- Generating done (0.0s)
-- Build files have been written to: /home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/build
☁  build [main] ⚡  make install  # 此处需安装后打包
[ 25%] Building C object math/CMakeFiles/math.dir/math.c.o
[ 50%] Linking C shared library /home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/lib/libmath.so
[ 50%] Built target math
[ 75%] Building C object CMakeFiles/app.dir/src/main.c.o
[100%] Linking C executable /home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/bin/app
[100%] Built target app
Install the project...
-- Install configuration: ""
-- Installing: /home/zhaoyang/.local/usr/bin/app
-- Set non-toolchain portion of runtime path of "/home/zhaoyang/.local/usr/bin/app" to ""
-- Installing: /home/zhaoyang/.local/usr/include/config.h
-- Up-to-date: /home/zhaoyang/.local/usr/include/my_math.h
-- Installing: /home/zhaoyang/.local/usr/bin/libmath.so
☁  build [main] ⚡  cpack -C CPackConfig.cmake  # 使用二进制打包
CPack: Create package using STGZ
CPack: Install projects
CPack: - Run preinstall target for: app
CPack: - Install project: app [CPackConfig.cmake]
CPack: Create package
CPack: - package: /home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/build/app-1.0.1-Linux.sh generated.
CPack: Create package using TGZ
CPack: Install projects
CPack: - Run preinstall target for: app
CPack: - Install project: app [CPackConfig.cmake]
CPack: Create package
CPack: - package: /home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/build/app-1.0.1-Linux.tar.gz generated.
CPack: Create package using TZ
CPack: Install projects
CPack: - Run preinstall target for: app
CPack: - Install project: app [CPackConfig.cmake]
CPack: Create package
CPack: - package: /home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/build/app-1.0.1-Linux.tar.Z generated.
☁  build [main] ⚡                            
☁  build [main] ⚡  ls
app-1.0.1-Linux.sh      app-1.0.1-Linux.tar.Z  CMakeFiles           CPackConfig.cmake  CPackSourceConfig.cmake  install_manifest.txt  math
app-1.0.1-Linux.tar.gz  CMakeCache.txt         cmake_install.cmake  _CPack_Packages    CTestTestfile.cmake      Makefile
☁  build [main] ⚡  ./app-1.0.1-Linux.sh      # 本地安装
app Installer Version: 1.0.1, Copyright (c) Cherub
This is a self-extracting archive.
The archive will be extracted to: /home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/build

If you want to stop extracting, please press <ctrl-C>.
The MIT License (MIT)

Copyright (c) 2013 Joseph Pan(http://hahack.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


Do you accept the license? [yn]: 
y
By default the app will be installed in:
  "/home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/build/app-1.0.1-Linux"  # 默认安装到当前目录
Do you want to include the subdirectory app-1.0.1-Linux?
Saying no will install in: "/home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/build" [Yn]: 
y

Using target directory: /home/zhaoyang/learning/learning_demo/01.CMAKE/demo7/build/app-1.0.1-Linux
Extracting, please wait...

Unpacking finished successfully
☁  build [main] ⚡  ls
app-1.0.1-Linux     app-1.0.1-Linux.tar.gz  CMakeCache.txt  cmake_install.cmake  _CPack_Packages          CTestTestfile.cmake   Makefile
app-1.0.1-Linux.sh  app-1.0.1-Linux.tar.Z   CMakeFiles      CPackConfig.cmake    CPackSourceConfig.cmake  install_manifest.txt  math
☁  build [main] ⚡  cd app-1.0.1-Linux/bin    
☁  bin [main] ⚡  ls
app  libmath.so
☁  bin [main] ⚡  ./app 2 5      # 执行失败，找不到libmath.so动态库
./app: error while loading shared libraries: libmath.so: cannot open shared object file: No such file or directory
☁  bin [main] ⚡  LD_DEBUG=files ./app
      4374:
      4374:     file=libmath.so [0];  needed by ./app [0]
./app: error while loading shared libraries: libmath.so: cannot open shared object file: No such file or directory
☁  bin [main] ⚡  export LD_PRELOAD=./libmath.so # 在这里直接使用LD_PRELOAD改变默认动态库搜索路径
☁  bin [main] ⚡  LD_DEBUG=files ./app      # 使用LD_DEBUG=files可以打印出动态库的加载过程    
      4474:
      4474:     file=./libmath.so [0];  needed by ./app [0]
      4474:     file=./libmath.so [0];  generating link map
      4474:       dynamic: 0x00007430404a8e80  base: 0x00007430404a5000   size: 0x0000000000004028
      4474:         entry: 0x00007430404a5000  phdr: 0x00007430404a5040  phnum:                 11
      4474:
      4474:
      4474:     file=libc.so.6 [0];  needed by ./app [0]
      4474:     file=libc.so.6 [0];  generating link map
      4474:       dynamic: 0x0000743040419bc0  base: 0x0000743040200000   size: 0x0000000000228e50
      4474:         entry: 0x0000743040229f50  phdr: 0x0000743040200040  phnum:                 14
      4474:
      4474:
      4474:     calling init: /lib64/ld-linux-x86-64.so.2
      4474:
      4474:
      4474:     calling init: /lib/x86_64-linux-gnu/libc.so.6
      4474:
      4474:
      4474:     calling init: ./libmath.so
      4474:
      4474:
      4474:     initialize program: ./app
      4474:
      4474:
      4474:     transferring control: ./app
      4474:
./app Version 1.0
Usage: ./app base exp
      4474:
      4474:     calling fini: ./app [0]
      4474:
      4474:
      4474:     calling fini: ./libmath.so [0]
      4474:
☁  bin [main] ⚡  ./app 10 5                    
Now we use our own math library. 
10 ^ 5 = 100000
☁  bin [main] ⚡  unset LD_PRELOAD # 去除LD_PRELOAD，否则会影响全局使用
```