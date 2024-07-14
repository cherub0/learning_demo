/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-14 19:15:10
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-14 20:21:05
 * @FilePath     : /learning/01.CMAKE/demo4/sort/selectSort.c
 * @Description  : selectSort 
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#include "sort.h"

/**
 * @description  : 选择排序
 * @param         {int} arr:
 * @param         {int} len:
 * @return        {*}
**/
void selectSort(int arr[], int len) 
{
    int i, j, minIndex, temp;
    for (i = 0; i < len - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < len; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        printStep(arr, len, i);
    }
}