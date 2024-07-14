#### demo4

测试嵌套`CMAKE`的使用：
* `CMakeLists.txt`中包含`add_subdirectory`命令，用于添加子目录，子目录中包含自己的`CMakeLists.txt`文件
* `add_subdirectory`命令会递归地调用子目录中的`CMakeLists.txt`文件，从而实现嵌套构建
* 根节点`CMakeLists.txt`中的变量全局有效
* 父节点`CMakeLists.txt`中的变量可以在子节点中使用
* 子节点`CMakeLists.txt`中的变量只能在当前节点中使用

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
-- Configuring done (3.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/zhaoyang/learning/learning_demo/01.CMAKE/demo4/build


☁  build [main] ⚡  make
# 构建calc目录，生成libcalc.so动态库
[  7%] Building C object calc/CMakeFiles/calc.dir/add.c.o
[ 15%] Building C object calc/CMakeFiles/calc.dir/div.c.o
[ 23%] Building C object calc/CMakeFiles/calc.dir/mul.c.o
[ 30%] Building C object calc/CMakeFiles/calc.dir/sub.c.o
[ 38%] Linking C shared library /home/zhaoyang/learning/learning_demo/01.CMAKE/demo4/lib/libcalc.so
[ 38%] Built target calc
# 构建sort目录，生成libsort.so动态库
[ 46%] Building C object sort/CMakeFiles/sort.dir/bubbleSort.c.o
[ 53%] Building C object sort/CMakeFiles/sort.dir/insertSort.c.o
[ 61%] Building C object sort/CMakeFiles/sort.dir/selectSort.c.o
[ 69%] Linking C shared library /home/zhaoyang/learning/learning_demo/01.CMAKE/demo4/lib/libsort.so
[ 69%] Built target sort
# 构建app目录，生成可执行文件app_calc和app_sort
[ 76%] Building C object src/CMakeFiles/app_calc.dir/calc.c.o
[ 84%] Linking C executable /home/zhaoyang/learning/learning_demo/01.CMAKE/demo4/bin/app_calc
[ 84%] Built target app_calc
[ 92%] Building C object test/CMakeFiles/app_sort.dir/sort.c.o
[100%] Linking C executable /home/zhaoyang/learning/learning_demo/01.CMAKE/demo4/bin/app_sort
[100%] Built target app_sort

☁  build [main] ⚡  ../bin/app_calc
a + b = 103
a - b = 97
a / b = 33.333333
a * b = 300

☁  build [main] ⚡  ../bin/app_sort 
bubbleSort: 
Step 0: 0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 
selectSort: 
Step 0: 0 3 5 7 9 2 4 6 8 1 
Step 1: 0 1 5 7 9 2 4 6 8 3 
Step 2: 0 1 2 7 9 5 4 6 8 3 
Step 3: 0 1 2 3 9 5 4 6 8 7 
Step 4: 0 1 2 3 4 5 9 6 8 7 
Step 5: 0 1 2 3 4 5 9 6 8 7 
Step 6: 0 1 2 3 4 5 6 9 8 7 
Step 7: 0 1 2 3 4 5 6 7 8 9 
Step 8: 0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 
insertSort: 
Step 1: 1 3 5 7 9 2 4 6 8 0 
Step 2: 1 3 5 7 9 2 4 6 8 0 
Step 3: 1 3 5 7 9 2 4 6 8 0 
Step 4: 1 3 5 7 9 2 4 6 8 0 
Step 5: 1 2 3 5 7 9 4 6 8 0 
Step 6: 1 2 3 4 5 7 9 6 8 0 
Step 7: 1 2 3 4 5 6 7 9 8 0 
Step 8: 1 2 3 4 5 6 7 8 9 0 
Step 9: 0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 
```
