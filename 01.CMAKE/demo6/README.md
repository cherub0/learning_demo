#### demo6

测试基本的`CMAKE`命令：
* `install`：指定安装规则
  默认安装路径：
  * `bin`：`/usr/local/bin`
  * `include`：`/usr/local/include`
* `CMAKE_INSTALL_PREFIX`：自定义安装路径
* `enable_testing`：启用测试
* `add_test`：添加测试用例
* `set_tests_properties`：设置测试的属性


构建：
```shell

# test install
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
ON
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /home/zhaoyang/learning/learning_demo/01.CMAKE/demo6/build
☁  build [main] ⚡  cat ../include/config.h
/* #undef USE_MYMATH */
☁  build [main] ⚡  ccmake ..              


☁  build [main] ⚡  sudo make install
[ 25%] Building C object math/CMakeFiles/math.dir/math.c.o
[ 50%] Linking C shared library ../../lib/libmath.so
[ 50%] Built target math
[ 75%] Building C object CMakeFiles/app.dir/src/main.c.o
[100%] Linking C executable ../bin/app
[100%] Built target app
Install the project...
-- Install configuration: ""
-- Installing: /usr/local/bin/app
-- Set runtime path of "/usr/local/bin/app" to ""
-- Installing: /usr/local/include/config.h
-- Up-to-date: /usr/local/include/my_math.h
-- Installing: /usr/local/bin/libmath.so
☁  build [main] ⚡  ls -al /usr/local/bin/
总用量 58580
drwxr-xr-x  2 root root     4096 Jul 16 21:53 .
drwxr-xr-x 12 root root     4096 Jul 14 09:32 ..
-rwxr-xr-x  1 root root    16112 Jul 16 21:53 app
-rwxr-xr-x  1 root root 19151824 Jul 14 09:29 cmake
-rwxr-xr-x  1 root root 19702720 Jul 14 09:30 cpack
-rwxr-xr-x  1 root root 21082736 Jul 14 09:29 ctest
-rw-r--r--  1 root root    15208 Jul 16 21:53 libmath.so
☁  build [main] ⚡  ls -al /usr/local/include 
总用量 16
drwxr-xr-x  2 root root 4096 Jul 16 21:53 .
drwxr-xr-x 12 root root 4096 Jul 14 09:32 ..
-rw-r--r--  1 root root   19 Jul 16 21:53 config.h
-rw-r--r--  1 root root  401 Jul 16 21:44 my_math.h

# 自定义安装路径
☁  build [main] ⚡  ls -al /home/zhaoyang/.local/usr/bin 
总用量 40
drwxrwxr-x 2 zhaoyang zhaoyang  4096 Jul 16 22:17 .
drwxrwxr-x 5 zhaoyang zhaoyang  4096 Jul 16 22:13 ..
-rwxr-xr-x 1 zhaoyang zhaoyang 16112 Jul 16 22:17 app
-rw-r--r-- 1 zhaoyang zhaoyang 15208 Jul 16 22:17 libmath.so
☁  build [main] ⚡  ls -al /home/zhaoyang/.local/usr/include 
总用量 16
drwxrwxr-x 2 zhaoyang zhaoyang 4096 Jul 16 22:15 .
drwxrwxr-x 5 zhaoyang zhaoyang 4096 Jul 16 22:13 ..
-rw-r--r-- 1 zhaoyang zhaoyang   19 Jul 16 22:15 config.h
-rw-r--r-- 1 zhaoyang zhaoyang  401 Jul 16 21:44 my_math.h


☁  build [main] ⚡  make test
Running tests...
Test project /home/zhaoyang/learning/learning_demo/01.CMAKE/demo6/build
    Start 1: test_2_10
1/4 Test #1: test_2_10 ........................   Passed    0.00 sec
    Start 2: test_3_5
2/4 Test #2: test_3_5 .........................   Passed    0.00 sec
    Start 3: test_8_6
3/4 Test #3: test_8_6 .........................   Passed    0.00 sec
    Start 4: test_10_5
4/4 Test #4: test_10_5 ........................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 4

Total Test time (real) =   0.02 sec
```