#### demo3

测试`CMAKE`自定义宏：
* `add_definitions`：添加自定义宏

编译输出结果：
```shell
# 未添加DEBUG宏
☁  build  ../bin/app
NODEBUG mode, a = 10
Hello, World!

# 添加DEBUG宏
☁  build  ../bin/app
DEBUG mode, a = 3
Hello, World!

```