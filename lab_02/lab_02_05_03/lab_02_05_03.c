/*!
 * \brief Лабораторная работа 2, задание 5, вариант 3
 * Вычислить и вывести на экран значение
 * min (𝐴[0] · 𝐴[1], 𝐴[1] · 𝐴[2], 𝐴[2] · 𝐴[3], . . . , 𝐴[𝑛 − 3] · 𝐴[𝑛 − 2], 𝐴[𝑛 − 2] · 𝐴[𝑛 − 1]) ,
 * где 𝑛 — размер массива.
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define N 10
#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

/*!
 * \brief input Инициализация массива
 * \param pb - указатель на первый элемент массива
 * \param pe - указатель на элемент за последним элементом массива
 */
void input(int *pb, int *pe)
{
    int *pcur = pb;
    while (pcur < pe)
    {
        printf("Введите элемент массива: ");
        if (scanf("%d", pcur) != 1)
        {
            printf("Ошибка, элементы должны быть целочисленными\n");
            exit(INPUT_ERROR);
        }
        pcur++;
    }
}

/*!
 * \brief min Минимальное произведение двух соседних элементов
 * \param pb - указатель на первый элемент массива
 * \param pe - указатель на элемент за последним элементом массива
 * \return - минимальное произведение двух соседних элементов
 */
int min(int *pb, int *pe)
{
    int min_term = *(pb + 1) * (*pb);
    while (pb < pe - 1)
    {
        if (*(pb + 1) * (*pb) < min_term)
            min_term = *(pb + 1) * (*pb);
        pb++;
    }
    return min_term;
}

/// Основная функция
int main(void)
{
    int n;
    printf("Введите количество элементов в массиве: ");
    if (scanf("%d", &n) == 0)
    {
        printf("Ошибка, это не число\n");
        return INPUT_ERROR;
    }
    else if (n <= 0 || n > N)
    {
        printf("Введенное число не в заданном промежутке\n");
        return INPUT_ERROR;
    }
    else if (n == 1)
    {
        printf("Для одного элемента невозможно посчитать слагаемое\n");
        return VALUE_ERROR;
    }
    int a[N];
    input(a, a + n);
    printf("%d\n", min(a, a + n));
    return SUCCESS;
}

