/*!
 * \brief Лабораторная работа 3, задание 2, вариант 0
 * Вставить строку из чисел 100 после каждой строки, в которой количество эле-
 * ментов, начинающихся на заданную цифру, равно количеству элементов, за-
 * канчивающихся на эту же цифру. В ситуации, когда таких чисел не обнаруже-
 * но вообще, строку из сотен не вставлять. Цифра вводится в виде числа после
 * ввода матрицы.
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
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
    int a[2 * M][N];
    int m, n;
    int m_new;
    int q;
    input(a, &m, &n);
    m_new = m;
    printf("Введите цифру: ");
    if (scanf("%d", &q) != 1 || q < 0 || q >= 10)
    {
        printf("Ошибка, это не цифра\n");
        return INPUT_ERROR;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (first_digit(a[i], n, q) == last_digit(a[i], n, q) && first_digit(a[i], n, q) != 0)
        {
            add_row(a, n, i);
            m_new++;
        }
    }
    print(a, m_new, n);
    return SUCCESS;
}
