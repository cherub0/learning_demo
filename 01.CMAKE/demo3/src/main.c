/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-14 18:02:09
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-14 18:18:00
 * @FilePath     : /learning/01.CMAKE/demo3/src/main.c
 * @Description  : test cmake macro
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#include <stdio.h>

int main()
{
    int a = 10;

#ifdef DEBUG
    a = 3;
    printf("DEBUG mode, a = %d\n", a);
#else
    printf("NODEBUG mode, a = %d\n", a);
#endif

    printf("Hello, World!\n");
    return 0;
}