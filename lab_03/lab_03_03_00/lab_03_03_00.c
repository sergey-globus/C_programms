/*!
 * \brief Лабораторная работа 3, задание 3, вариант 0
 * Упорядочить строки матрицы по возрастанию суммы их элементов
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
    input(a, &m, &n);
    for (int i = 1; i < m; i++)
        for (int j = 0; j < m - i; j++)
            if (sum(a[j], n) > sum(a[j + 1], n))
                swap(a[j], a[j + 1], n);
    print(a, m, n);
    return SUCCESS;
}
