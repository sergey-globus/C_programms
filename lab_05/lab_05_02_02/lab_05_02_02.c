/*!
 * \brief Лабораторная работа 5, задание 2, вариант 2
 * рассчитать дисперсию чисел (Дисперсией ряда чисел называется среднее арифметическое
 * квадратов их отклонений от среднего арифметического этого ряда)
 */

#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/// Основная функция
int main(int argc, char **argv)
{
    if (argc != 2)
        return ARG_ERROR;

    FILE *f;
    f = fopen(argv[1], "r");

    if (f == NULL)
        return IO_ERROR;

    int n = 0;
    double middler = 0;
    int rv = average(f, &n, &middler);
    if (rv != 0)
        return EMPTY;
    fclose(f);

    f = fopen(argv[1], "r");
    double disperse = 0;
    if (n != 1)
    {
        dispersion(f, &disperse, middler);
        disperse /= n;
    }
    else
        disperse = 0;
    printf("%f", disperse);
    fclose(f);
    return OK;
}
