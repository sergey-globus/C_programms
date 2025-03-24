/*!
 * \brief Лабораторная работа 1, задание 5, вариант 1
 * С клавиатуры вводятся целое положительное 𝑎 и целое положительное 𝑑. Вы-
 * числить и вывести на экран частное 𝑞 и остаток 𝑟 при делении 𝑎 на 𝑑, не
 * используя операций целочисленного деления.
 */

#include <stdio.h>
#define SUCCESS 0 /// Код успешного завершения
#define INPUT_ERROR 1 /// Код ошибки валидности данных
#define VALUE_ERROR 2 /// Код ошибки значения данных

/*!
 * \brief divide Целочисленное деление двух чисел
 * \param a - первое число
 * \param d - второе число
 * \return - частное от деления
 */
int divide(int a, int d)
{
    int i = 0;
    while (a >= d)
    {
        i++;
        a -= d;
    }
    return i;
}

/// Основная функция
int main(void)
{
    int a, d;
    int q, r;
    printf("Введите первое положительное число: ");
    if (scanf("%d", &a) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    if (a <= 0)
    {
        printf("Ошибка, это не положительное число.\n");
        return VALUE_ERROR;
    }
    printf("Введите второе положительное число: ");
    if (scanf("%d", &d) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    if (d <= 0)
    {
        printf("Ошибка, это не положительное число.\n");
        return VALUE_ERROR;
    }
    q = divide(a, d);
    r = a - q * d;
    printf("%d\n", q);
    printf("%d\n", r);
    return SUCCESS;
}

