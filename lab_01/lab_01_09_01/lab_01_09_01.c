/*!
 * \brief Лабораторная работа 1, задание 9, вариант 1
 * Приняв с клавиатуры по концевому признаку (до первого отрицательного чис-
 * ла) элементы непустой последовательности неотрицательных чисел 𝑥, вычислить и
 * вывести на экран значение 𝑔(𝑥).
 * g(x) = sin(sqrt(x1) + sqrt(x2 / 2) + ... + sqrt(xn / n))
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SUCCESS 0 /// Код успешного завершения
#define INPUT_ERROR 1 /// Код ошибки валидности данных
#define VALUE_ERROR 2 /// Код ошибки значения данных

/*!
 * \brief g Вычисление функции g(x)
 * \return - Значение функции g(x)
 */
double g(void)
{
    double sum = 0;
    double x;
    int i = 0;
    if (scanf("%lf", &x) == 0)
    {
        printf("Ошибка, это не число\n");
        exit(INPUT_ERROR);
    }
    if (x < 0)
    {
        printf("Ошибка, нет ни одного положительного числа\n");
        exit(VALUE_ERROR);
    }
    while (x >= 0)
    {
        sum += sqrt(x / ++i);
        if (scanf("%lf", &x) == 0)
        {
            printf("Ошибка, это не число\n");
            exit(INPUT_ERROR);
        }
    }
    return sin(sum);
}

/// Основная функция
int main(void)
{
    printf("%lf\n", g());
    return SUCCESS;
}

