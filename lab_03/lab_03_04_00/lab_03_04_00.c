/*!
 * \brief Лабораторная работа 3, задание 4, вариант 0
 * Найти и вывести на экран минимальное нечётное число, расположенное под
 * главной диагональю.
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "input.h"
#include "functions.h"
#define N 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

int main(void)
{
    int a[N][N];
    int m, n;
    input(a, &m, &n);
    printf("%d\n", min_odd(a, n));
    return SUCCESS;
}
