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

float mean_value(int *a, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum / n;
}

void new_massive(int *a, int n, int *b, float mean)
{
    for (int i = 0, k = 0; i < n; i++)
        if (a[i] > mean)
            b[k++] = a[i];
}

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
}

int main(void)
{
    int n, n_new = 0;
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
    float mean = mean_value(a, n);
    for (int i = 0; i < n; i++)
        if (a[i] > mean)
            n_new++;
    if (n_new == 0)
    {
        printf("В массиве все числа одинаковые\n");
        return VALUE_ERROR;
    }
    int b[N];
    new_massive(a, n, b, mean);
    print(b, n_new);
    return SUCCESS;
}

