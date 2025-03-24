#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

/*!
 * \brief sum Сумма элементов в строке
 * \param a - указатель на строку
 * \param n - количество элементов в строке
 * \return - сумма
 */
int sum(int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

/*!
 * \brief print Вывод матрицы
 * \param a - указатель на матрицу
 * \param m - количество строк
 * \param n - количество столбцов
 */
void print(int a[][N], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

/*!
 * \brief swap - Свап двух строчек
 * \param a - указатель на первую строку
 * \param b - указатель на вторую строку
 * \param n - количество элементов в строке
 */
void swap(int *a, int *b, int n)
{
    int c;
    for (int i = 0; i < n; i++)
    {
        c = a[i];
        a[i] = b[i];
        b[i] = c;
    }
}
