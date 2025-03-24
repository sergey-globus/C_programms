/*!
 * \brief Лабораторная работа 1, задание 8, вариант 1
 * Вводятся значения четырёх байт в десятичной системе счисления. Необходимо
 * реализовать «упаковку» этих байт в беззнаковое целое (первый байт занимает
 * самые старшие биты беззнакового числа, последний – самые младшие) и «рас-
 * паковку» обратно. Вывести сначала результат «упаковки» (беззнаковое целое)
 * в двоичной системе счисления, затем значения четырёх байт, полученных в ре-
 * зультате «распаковки» (от старшего к младшему) в десятичной системе счис-
 * ления.
 */

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#define SUCCESS 0 /// Код успешного завершения
#define INPUT_ERROR 1 /// Код ошибки валидности данных
#define VALUE_ERROR 2 /// Код ошибки значения данных
#define BIT_IN_BYTE 8 /// Количество бит в одном байте

/*!
 * \brief pack Упаковка 4-х байт в беззнаковое целое
 * \param a - значение первого байта
 * \param b - значение второго байта
 * \param c - значение третьего байта
 * \param d - значение четвертого байта
 * \return - значение 4-х байт в беззнаковом целом
 */
uint32_t pack(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    uint32_t res;
    res = (a << 3 * BIT_IN_BYTE) + (b << 2 * BIT_IN_BYTE) + (c << BIT_IN_BYTE) + d;
    return res;
}

/*!
 * \brief in_2 Вывод числа в двоичной системе счисления
 * \param res - число в десятичной системе счисления
 */
void in_2(uint32_t res)
{
    printf("Result: ");
    for (int i = 4 * BIT_IN_BYTE - 1; i >= 0; i--)
        printf("%d", (res / (int) pow(2, i)) % 2);
}

/*!
 * \brief unpack Распаковка числа на байты и их вывод
 * \param res - число
 */
void unpack(unsigned int res)
{
    uint8_t a, b, c, d;
    a = res >> 3 * BIT_IN_BYTE;
    printf(" %d", a);
    res -= a * (int) pow(2, BIT_IN_BYTE * 3);
    b = res >> 2 * BIT_IN_BYTE;
    printf(" %d", b);
    res -= b * (int) pow(2, BIT_IN_BYTE * 2);
    c = res >> BIT_IN_BYTE;
    printf(" %d", c);
    res -= c * (int) pow(2, BIT_IN_BYTE);
    d = res;
    printf(" %d", d);
}

/// Основная функция
int main(void)
{
    int a, b, c, d;
    uint8_t a1, b1, c1, d1;
    uint32_t res;
    if (scanf("%d", &a) == 0)
    {
        printf("Error: not number");
        return INPUT_ERROR;
    }
    if (a < 0 || a > (int) pow(2, BIT_IN_BYTE) - 1)
    {
        printf("Error: value error");
        return VALUE_ERROR;
    }
    a1 = a;
    if (scanf("%d", &b) == 0)
    {
        printf("Error: not number");
        return INPUT_ERROR;
    }
    if (b < 0 || b > (int) pow(2, BIT_IN_BYTE))
    {
        printf("Error: value error");
        return VALUE_ERROR;
    }
    b1 = b;
    if (scanf("%d", &c) == 0)
    {
        printf("Error: not number");
        return INPUT_ERROR;
    }
    if (c < 0 || c > (int) pow(2, BIT_IN_BYTE))
    {
        printf("Error: value error");
        return VALUE_ERROR;
    }
    c1 = c;
    if (scanf("%d", &d) == 0)
    {
        printf("Error: not number");
        return INPUT_ERROR;
    }
    if (d < 0 || d > (int) pow(2, BIT_IN_BYTE))
    {
        printf("Error: value error");
        return VALUE_ERROR;
    }
    d1 = d;
    res = pack(a1, b1, c1, d1);
    in_2(res);
    unpack(res);
    return SUCCESS;
}

