#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

/*!
 * \brief input Ввод матрицы ходом быка
 * \param a - указатель на матрицу
 * \param m - количество строк
 * \param n - количество столбцов
 */
void input(int a[][N], int m, int n)
{
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < m; j++)
            {
                a[j][i] = k++;
            }
        else
            for (int j = 0; j < m; j++)
            {
                a[m - 1 - j][i] = k++;
            }
    }
}
