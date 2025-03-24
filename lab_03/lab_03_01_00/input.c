#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

/*!
 * \brief input Ввод размерности и элементов матрицы
 * \param a - матрица
 * \param n - указатель на кол-во столбцов
 * \param m - указатель на кол-во строк
 */
void input(int a[][M], int *m, int *n)
{
    printf("Введите количество строк: ");
    if (scanf("%d", m) != 1)
    {
        printf("Ошибка, это не число\n");
        exit(INPUT_ERROR);
    }

    if (*m <= 0 || *m > M)
    {
        printf("Ошибка, введенное число не в заданном промежутке\n");
        exit(INPUT_ERROR);
    }

    printf("Введите количество столбцов: ");
    if (scanf("%d", n) != 1)
    {
        printf("Ошибка, это не число\n");
        exit(INPUT_ERROR);
    }

    if (*n <= 0 || *n > M)
    {
        printf("Ошибка, введенное число не в заданном промежутке\n");
        exit(INPUT_ERROR);
    }

    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *n; j++)
            if (scanf("%d", &a[i][j]) != 1)
            {
                printf("Ошибка, элементы должны быть целочисленными\n");
                exit(INPUT_ERROR);
            }
}
