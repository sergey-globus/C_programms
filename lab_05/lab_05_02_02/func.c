/// Вычисление дисперсии чисел

#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/*!
 * \brief average Вычисление среднего арифметического чисел из файла
 * \param f файл
 * \param n количество чисел
 * \param middler среднее арифметическое
 * \return как все прошло
 */
int average(FILE *f, int *n, double *middler)
{
    double value;
    int error = 0;
    while (!feof(f) && fscanf(f, "%lf", &value) == 1)
    {
        error = 1;
        *middler += value;
        *n = *n + 1;
    }

    if (error == 0)
        return EMPTY;
    *middler /= *n;
    return OK;
}

/*!
 * \brief dispersion Вычисление дисперсии чисел из файла
 * \param f файл
 * \param disperse дисперсия чисел
 * \param middler среднее арифметическое чисел
 */
void dispersion(FILE *f, double *disperse, double middler)
{
    double value;
    while (!feof(f) && fscanf(f, "%lf", &value) == 1)
    {
        (*disperse) += (value - middler) * (value - middler);
    }
}
