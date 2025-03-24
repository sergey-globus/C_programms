#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

/*!
 * \brief print - вывод списка
 * \param b - список
 * \param n - кол-во столбцов в искомой матрице
 * \return
 */
void print(int *b, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");
}

/*!
 * \brief sign Значение элементов одномерного массива
 * \param a - указатель на матрицу
 * \param m - количество строк
 * \param k - номер столбца
 * \return - 1-элементы в столбце упорядочены по убыванию/0-не упорядочены
 */
int sign(int a[][M], int m, int k)
{
    int back = a[0][k];
    if (m == 1)
        return 0;
    for (int i = 1; i < m; i++)
    {
        if (a[i][k] >= back)
            return 0;
        back = a[i][k];
    }
    return 1;
}
