#### demo5

测试基本的`CMAKE`命令：
* `configure_file`：加入一个配置文件，通过`cmake`/`ccmake`可构建生成`config.h`
* `option`：设置配置默认值，可通过`ccmake`选择
* `if()`、`else()`、`endif()`：条件控制语句


构建：
```shell
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
-- Build files have been written to: /home/zhaoyang/learning/learning_demo/01.CMAKE/demo5/build
☁  build [main] ⚡  cat ../include/config.h      
/* #undef USE_MYMATH */
☁  build [main] ⚡  ccmake ..  # 选择为ON


☁  build [main] ⚡  cat ../include/config.h
#define USE_MYMATH
☁  build [main] ⚡  make
[ 25%] Building C object math/CMakeFiles/math.dir/math.c.o
[ 50%] Linking C shared library ../../lib/libmath.so
[ 50%] Built target math
[ 75%] Building C object CMakeFiles/app.dir/src/main.c.o
[100%] Linking C executable ../bin/app
[100%] Built target app
☁  build [main] ⚡  ../bin/app 2 10
Now we use our own math library. 
2 ^ 10 = 1024

☁  build [main] ⚡  ccmake .. # 选择为OFF


☁  build [main] ⚡  make
Consolidate compiler generated dependencies of target app
[ 50%] Building C object CMakeFiles/app.dir/src/main.c.o
[100%] Linking C executable ../bin/app
[100%] Built target app
☁  build [main] ⚡  ../bin/app 2 10
Now we use the standard library. 
2 ^ 10 = 1024
```

ccmake使用：
![ccmake](https://raw.gitmirror.com/cherub0/picgo-img/master/202407162135394.jpg)