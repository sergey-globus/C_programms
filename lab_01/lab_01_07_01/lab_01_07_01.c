/*!
 * \brief Лабораторная работа 1, задание 7, вариант 1
 * Приняв с клавиатуры 𝑥 и 𝜀, 0 < 𝜀 ⩽ 1, вывести на экран вычисленное с точно-
 * стью 𝜀 приближённое значение 𝑠(𝑥) и точное значение 𝑓 (𝑥) функции 𝑓 , абсолютную
 * ∆ и относительную 𝛿 погрешности:
 * ∆ = |𝑓 (𝑥) − 𝑠(𝑥)|,
 * 𝛿=|𝑓 (𝑥) − 𝑠(𝑥)|/|𝑓 (𝑥)|,
 * ∀𝑥 𝑓 (𝑥) = sin(𝑥), 𝑠(𝑥) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9! + ...
 */

#include <stdio.h>
#include <math.h>
#define SUCCESS 0 /// Код успешного завершения
#define INPUT_ERROR 1 /// Код ошибки валидности данных
#define VALUE_ERROR 2 /// Код ошибки значения данных

/*!
 * \brief f Точное значение функции
 * \param x - аргумент функции
 * \return - значение функции
 */
double f(double x)
{
    return sin(x);
}

/*!
 * \brief s Приближенное значение функции
 * \param x - аргумент функции
 * \param eps - заданная погрешность
 * \return - значение функции
 */
double s(double x, double eps)
{
    double sin_x = 0;
    int i = 1;
    double el = x;
    while (fabs(el) > eps)
    {
        sin_x += el;
        i += 2;
        el = (-1) * el * pow(x, 2) / (i * (i - 1));
    }
    return sin_x;
}

/// Основная функция
int main(void)
{
    double x;
    double eps;
    double relative, absolute;
    printf("Введите x: ");
    if (scanf("%lf", &x) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    printf("Введите значени eps от нуля (невключительно) до единицы: ");
    if (scanf("%lf", &eps) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    if (eps <= 0 || eps > 1)
    {
        printf("Ошибка, значение вне промежутка\n");
        return VALUE_ERROR;
    }
    double s_x = s(x, eps);
    double f_x = f(x);
    printf("%lf\n", s_x);
    printf("%lf\n", f_x);
    absolute = fabs(s_x - f_x);
    relative = absolute / fabs(f_x);
    printf("%lf\n", absolute);
    printf("%lf\n", relative);
    return SUCCESS;
}

