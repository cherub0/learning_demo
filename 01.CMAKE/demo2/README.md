#### demo2

测试基本的`CMAKE`语法：
* `list`：字符串拼接，常用于搜索到的源文件字符串拼接
  ```cmake
    # 将一个或多个元素追加到指定的列表中。
    list(APPEND <list> [<element> ...])

    # 从指定的列表中移除一个或多个值。
    list(REMOVE_ITEM <list> <value> [<value> ...])

    # 获取指定列表的长度，并将结果存储在指定的输出变量中。
    list(LENGTH <list> <output variable>)

    # 从指定的列表中获取一个或多个元素，并将结果存储在指定的输出变量中。
    list(GET <list> <element index> [<element index> ...] <output variable>)

    # 将列表中的元素用指定的连接符连接起来，并将结果存储在指定的输出变量中。
    list(JOIN <list> <glue> <output variable>)

    # 在指定的列表中查找指定的值，并将找到的索引存储在指定的输出变量中。
    list(FIND <list> <value> <output variable>)

    # 在指定的列表中的指定位置插入一个或多个元素。
    list(INSERT <list> <element_index> <element> [<element> ...])

    # 将一个或多个元素插入到指定列表的开头。
    list(PREPEND <list> [<element> ...])

    # 移除并返回指定列表的最后一个元素。如果指定了输出变量，则将移除的元素存储在输出变量中。
    list(POP_BACK <list> [<out-var>...])

    # 移除并返回指定列表的第一个元素。如果指定了输出变量，则将移除的元素存储在输出变量中。
    list(POP_FRONT <list> [<out-var>...])

    # 从指定的列表中移除一个或多个指定索引位置的元素。
    list(REMOVE_AT <list> <index> [<index> ...])

    # 从指定的列表中移除所有重复的元素。
    list(REMOVE_DUPLICATES <list>)

    # 对指定的列表进行排序。可以通过可选参数指定比较方式、大小写敏感和排序顺序。
    list(SORT <list> [COMPARE <compare>] [CASE <case>] [ORDER <order>])

  ```
* `LIBRARY_OUTPUT_PATH`：设置库文件的输出路径
* `add_library`：
    ```cmake
        # 添加一个库目标。
        add_library(<name> [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL]
                    [source1 [source2 ...]])
    ```
    * `STATIC`：静态库
    * `SHARED`：动态库
    * `MODULE`：模块库
    * `EXCLUDE_FROM_ALL`：从构建系统中排除该库
    * `source1 [source2 ...]`：源文件列表
* `target_link_libraries`：为目标链接库
    ```cmake
        # 为目标链接库。
        target_link_libraries(<target> [item1 [item2 ...]] [...])
    ``` 
    * `<target>`：目标名称
    * `[item1 [item2 ...]]`：库列表
    ```cmake
        target_link_libraries(mylib PRIVATE mylib)
    ```
    * `PRIVATE`：私有链接，只对当前目标有效
    ```cmake
        target_link_libraries(mylib INTERFACE mylib)
    ```
    * `INTERFACE`：接口链接，只对依赖当前目标的其他目标有效
    ```cmake
        target_link_libraries(mylib PUBLIC mylib)
    ```
    * `PUBLIC`：公共链接，对当前目标和依赖当前目标的其他目标都有效
* `set_target_properties`：设置目标属性，指定静态库名称
    ```cmake
        # 设置目标属性。
        set_target_properties(<target> PROPERTIES <prop1> <value1> [<prop2> <value2> ...])
    ``` 
    * `<target>`：目标名称
    * `<prop1> <value1> [<prop2> <value2> ...]`：属性和值对
* `link_libraries`：链接静态库

