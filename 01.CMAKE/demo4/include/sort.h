/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-14 19:57:28
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-14 20:30:23
 * @FilePath     : /learning/01.CMAKE/demo4/include/sort.h
 * @Description  : sort.h
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#ifndef _SORT_H_
#define _SORT_H_

#define TRUE 1
#define FALSE 0

void bubbleSort(int a[], int n);
void selectSort(int a[], int n);
void insertSort(int a[], int n);

void printStep(int *a, int len, int step);

#endif // _SORT_H_
