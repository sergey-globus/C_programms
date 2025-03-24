/*!
 * \brief Лабораторная работа 3, задание 1, вариант 0
 * По матрице получить и вывести на экран одномерный массив, присвоив его 𝑘-
 * тому элементу значение 1, если элементы 𝑘-го столбца упорядочены по убыванию,
 * и значение 0 в иных случаях
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "functions.h"
#define N 10
#define M 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

/// Основная функция
int main(void)
{
    int m, n; ///
    int a[M][N];
    int b[N];
    input(a, &m, &n);
    for (int i = 0; i < n; i++)
        b[i] = sign(a, m, i);
    print(b, n);
    return SUCCESS;
}
