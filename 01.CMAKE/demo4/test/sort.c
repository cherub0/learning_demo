/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-14 19:58:44
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-14 20:22:40
 * @FilePath     : /learning/01.CMAKE/demo4/test/sort.c
 * @Description  : sort test
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#include <stdio.h>
#include "sort.h"

/**
 * @description  : 打印每一步排序的结果
 * @param         {int} *a:
 * @param         {int} len:
 * @param         {int} step:
 * @return        {*}
**/
void printStep(int *a, int len, int step)
{
    int i = 0;
    printf("Step %d: ", step);
    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int i = 0;
    
    // int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int c[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};

    int len = sizeof(a) / sizeof(int);

    printf("bubbleSort: \n");
    bubbleSort(a, len);
    
    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("selectSort: \n");

    selectSort(b, len);
    for (i = 0; i < len; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("insertSort: \n");

    insertSort(c, len);
    for (i = 0; i < len; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}