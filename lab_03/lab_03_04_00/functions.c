#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

int min_odd(int a[][N], int n)
{
    int flag_odd = 0;
    int min_odd;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (abs(a[i][j]) % 2 == 1)
            {
                if (flag_odd == 0)
                {
                    flag_odd = 1;
                    min_odd = a[i][j];
                }
                else if (a[i][j] < min_odd)
                    min_odd = a[i][j];
            }
    if (flag_odd == 0)
    {
        printf("Ошибка, нет нечетных чисел под главной диагональю\n");
        exit(VALUE_ERROR);
    }
    return min_odd;
}
