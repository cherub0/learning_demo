/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-14 19:15:19
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-14 20:21:18
 * @FilePath     : /learning/01.CMAKE/demo4/sort/insertSort.c
 * @Description  : 
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#include "sort.h"

/**
 * @description  : 插入排序
 * @param         {int} *arr:
 * @param         {int} len:
 * @return        {*}
**/
void insertSort(int *arr, int len) {
    for (int i = 1; i < len; i++) 
    {
        int j = i - 1;
        int tmp = arr[i];
        while (j >= 0 && arr[j] > tmp) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;

        printStep(arr, len, i);
    }
}
