/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-14 18:57:50
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-14 20:23:03
 * @FilePath     : /learning/01.CMAKE/demo4/src/calc.c
 * @Description  : calc test
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#include <stdio.h>
#include "calc.h"

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