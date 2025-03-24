#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define N 10

#define SUCCESS 0
#define INPUT_ERROR 1
#define VALUE_ERROR 2

void input(int *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("Введите элемент массива: ");
        if (scanf("%d", a + i) != 1)
        {
            printf("Ошибка, элементы должны быть целочисленными\n");
            exit(INPUT_ERROR);
        }
    }
}

int sum_even(int *a, size_t n)
{
    int sum = 0;
    int no_even = 1;
    for (size_t i = 0; i < n; i++)
        if (a[i] % 2 == 0)
        {
            sum += a[i];
            no_even = 0;
        }

    if (no_even)
        return 1;
    else
        return sum;
}

int main(void)
{
    int n;
    printf("Введите количество элементов в массиве(максимум десять): ");
    int k = scanf("%d", &n);

    if (k == 0)
    {
        printf("Ошибка, это не число\n");
        return INPUT_ERROR;
    }
    else if (n <= 0 || n > N)
    {
        printf("Введенное число не в заданном промежутке\n");
        return INPUT_ERROR;
    }

    int a[N];
    input(a, n);
    int sum = sum_even(a, n);

    if (sum == 1)
    {
        printf("В масссиве нет четных чисел\n");
        return VALUE_ERROR;
    }
    printf("%d\n", sum);
        return SUCCESS;
}

