/*!
 * \brief Лабораторная работа 3, задание 6, вариант 0
 * Приняв с клавиатуры число строк и столбцов матрицы, заполнить прямоуголь-
 * ную целочисленную матрицу «ходом быка» с начала: нечётные столбцы про-
 * ходить сверху вниз, чётные — наоборот. Матрицу вывести на экран.
 * Пример:      1 6 7 12
 *              2 5 8 11
 *              3 4 9 10
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
    printf("Введите количество строк: ");
    if (scanf("%d", &m) != 1)
    {
        printf("Ошибка, это не число\n");
        return INPUT_ERROR;
    }
    if (m <= 0 || m > M)
    {
        printf("Ошибка, введенное число не в заданном промежутке\n");
        return INPUT_ERROR;
    }
    printf("Введите количество столбцов: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Ошибка, это не число\n");
        return INPUT_ERROR;
    }
    if (n <= 0 || n > N)
    {
        printf("Ошибка, введенное число не в заданном промежутке\n");
        return INPUT_ERROR;
    }
    input(a, m, n);
    print(a, m, n);
    return SUCCESS;
}
