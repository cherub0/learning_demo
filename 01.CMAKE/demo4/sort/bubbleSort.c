/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-14 19:15:00
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-14 20:20:54
 * @FilePath     : /learning/01.CMAKE/demo4/sort/bubbleSort.c
 * @Description  : bubbleSort
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#include "sort.h"

/**
 * @description  : 冒泡排序
 * @param         {int} arr:
 * @param         {int} n:
 * @return        {*}
**/
void bubbleSort(int arr[], int n)
{
    int flag = TRUE;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = FALSE;
            }
        }

        printStep(arr, n, i);

        if (flag)
        {
            break;
        }
    }
}