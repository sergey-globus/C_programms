/*!
 * \brief Лабораторная работа 1, задание 6, вариант 1
 * Принять с клавиатуры координаты 𝑥𝑎 , 𝑦𝑎 , 𝑥𝑏 , 𝑦𝑏 , 𝑥𝑐 , 𝑦𝑐 треугольника 𝑎𝑏𝑐 на
 * плоскости. Найти и вывести на экран площадь 𝑆 треугольника.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SUCCESS 0 /// Код успешного завершения
#define INPUT_ERROR 1 /// Код ошибки валидности данных
#define VALUE_ERROR 2 /// Код ошибки значения данных

/*!
 * \brief area Считает площадь треугольника
 * \param xa - координата х точки а
 * \param ya - координата y точки a
 * \param xb - координата х точки b
 * \param yb - координата y точки b
 * \param xc - координата х точки c
 * \param yc - координата y точки c
 * \return - площадь
 */
double area(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double ab = sqrt(pow((xa - xb), 2) + pow((ya - yb), 2));
    double bc = sqrt(pow((xb - xc), 2) + pow((yb - yc), 2));
    double ac = sqrt(pow((xa - xc), 2) + pow((ya - yc), 2));
    double max = ab;
    double eps = pow(10, -8);
    if (bc > max)
        max = bc;
    if (ac > max)
        max = ac;
    if (fabs(2 * max - (ab + bc + ac)) < eps)
    {
        printf("Ошибка, такого треугольника не существует\n");
        exit(VALUE_ERROR);
    }
    double p = (ab + bc + ac) / 2;
    double s = sqrt(p * (p - ab) * (p - bc) * (p - ac));
    return s;
}

/// Основная функция
int main(void)
{
    double xa, ya;
    double xb, yb;
    double xc, yc;
    printf("Введите координату х точки а: ");
    if (scanf("%lf", &xa) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    printf("Введите координату y точки а: ");
    if (scanf("%lf", &ya) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    printf("Введите координату х точки b: ");
    if (scanf("%lf", &xb) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    printf("Введите координату y точки b: ");
    if (scanf("%lf", &yb) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    printf("Введите координату х точки c: ");
    if (scanf("%lf", &xc) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    printf("Введите координату y точки c: ");
    if (scanf("%lf", &yc) == 0)
    {
        printf("Ошибка, это не число.\n");
        return INPUT_ERROR;
    }
    printf("%f\n", area(xa, ya, xb, yb, xc, yc));
    return SUCCESS;
}

