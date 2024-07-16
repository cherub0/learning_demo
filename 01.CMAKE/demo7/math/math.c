/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-15 22:15:39
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-15 22:17:09
 * @FilePath     : /learning_demo/01.CMAKE/demo5/math/math.c
 * @Description  : 
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#include "my_math.h"

double power(double base, int exp) 
{
    double result = base;

    if (exp == 0)
    {
        return 1;
    }

    for (int i = 1; i < exp; i++)
    {
        result *= base;
    }

    return result;
}