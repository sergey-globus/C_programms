#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

/*!
 * \brief is_simple Проверка на простое число
 * \param q - число
 * \return 1-правда/0-ложь
 */
int is_simple(int q)
{
    if (q < 1)
        return 0;
    if (q == 1)
        return 0;
    for (int i = 2; 1 == 1; i++)
    {
        if (i * i > q)
            return 1;
        if ((q / i) * i == q)
            return 0;
    }
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
 * \brief reverse Разворот массива
 * \param a - указатель на массив
 * \param n - количество элементов массива
 */
void reverse(int *a, int n)
{
    int c;
    for (int i = 0; i < n / 2; i++)
    {
        c = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = c;
    }
}
