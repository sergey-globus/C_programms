#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

/*!
 * \brief first_digit Количество чисел, начинающихся на заданную цифру
 * \param a - указатель на строку
 * \param n - количество элементов в строке
 * \param k - заданная цифра
 * \return - количество чисел, начинающихся на заданную цифру
 */
int first_digit(int *a, int n, int k)
{
    int quantity = 0;
    int digit;
    for (int i = 0; i < n; i++)
    {
        digit = abs(a[i]);
        while (digit >= 10)
            digit /= 10;
        if (digit == k)
            quantity += 1;
    }
    return quantity;
}

/*!
 * \brief last_digit Количество чисел, заканчивающихся на заданную цифру
 * \param a - указатель на строку
 * \param n - количество элементов в строке
 * \param q - заданная цифра
 * \return - количество чисел, заканчивающихся на заданную цифру
 */
int last_digit(int *a, int n, int q)
{
    int quantity = 0;
    for (int i = 0; i < n; i++)
        if (abs(a[i]) % 10 == q)
            quantity += 1;
    return quantity;
}

/*!
 * \brief add_row Добавление строки из сотен
 * \param a - указатель на матрицу
 * \param n - количество столбцов
 * \param k - индекс строки, после которой нужно добавить
 */
void add_row(int a[][N], int n, int k)
{
    for (int i = 2 * M - 1; i > k + 1 ; i--)
        for (int j = 0; j < n; j++)
            a[i][j] = a[i - 1][j];
    for (int j = 0; j < n; j++)
        a[k + 1][j] = 100;
}

/*!
 * \brief print Вывод матрицы
 * \param a - указатель на массив
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
