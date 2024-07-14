/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-14 10:39:50
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-14 11:05:13
 * @FilePath     : /learning/01.CMAKE/demo/main.c
 * @Description  : calc 
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#include <stdio.h>
#include "head.h"

int main(int argc, char *argv[])
{
	int a = 100;
	int b = 3;

	printf("a + b = %d\n", add(a, b));
	printf("a - b = %d\n", sub(a, b));
	printf("a / b = %f\n", div(a, b));
	printf("a * b = %d\n", mul(a, b));

	return 0;
}
