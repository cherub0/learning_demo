/**
 * @Author       : Cherub (ershengaaa@163.com)
 * @Date         : 2024-07-15 22:12:01
 * @LastEditors  : Cherub
 * @LastEditTime : 2024-07-15 23:04:57
 * @FilePath     : /learning_demo/01.CMAKE/demo5/src/main.c
 * @Description  : 
 * @
 * @Copyright (c) 2024 by Cherub, All Rights Reserved. 
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

#ifdef USE_MYMATH
    #include "my_math.h"
#else
    #include <math.h>
#endif

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s base exp\n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exp = atoi(argv[2]);

    double result = 0;

#ifdef USE_MYMATH
    printf("Now we use our own math library. \n");
    result = power(base, exp);
#else
    printf("Now we use the standard library. \n");
    result = pow(base, exp);
#endif

    printf("%g ^ %d = %g\n", base, exp, result);
    return 0;
}