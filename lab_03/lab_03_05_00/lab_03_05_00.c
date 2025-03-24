/*!
 * \brief Лабораторная работа 3, задание 5, вариант 0
 * Элементы матрицы, которые являются простыми числами, в порядке обхода
 * матрицы по строкам поместить в одномерный массив, развернуть массив, и
 * вернуть элементы из массива в матрицу в том же порядке, в котором они
 * помещались в массив. Если в матрице нет простых чисел, считать ситуацию
 * ошибочной.
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "input.h"
#include "functions.h"
#define M 10
#define N 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

/// Основная функция
int main(void)
{
    int a[M][N];
    int m, n;
    int b[M * N];
    int k = 0;
    input(a, &m, &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (is_simple(a[i][j]))
                b[k++] = a[i][j];
    if (k == 0)
    {
        printf("Ошибка, нет простых чисел\n");
        return VALUE_ERROR;
    }
    reverse(b, k);
    int k_index = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (is_simple(a[i][j]))
                a[i][j] = b[k_index++];
    print(a, m, n);
    return SUCCESS;
}
