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
int its_palindrome(int el)
{
    int k = el;
    int reverse_el = 0;
    while (k > 0)
    {
        reverse_el = 10 * reverse_el + k % 10;
        k /= 10;
    }
    if (el == reverse_el)
        return 1;
    else
        return 0;
}
void delete(int *a, size_t n, size_t pos)
{
    for (size_t i = pos; i < n - 1; i++)
        a[i] = a[i + 1];
}
void print(int *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
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

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0 && its_palindrome(a[i]))
        {
            delete(a, n, i);
            n--;
            i--;
        }
    }
    if (n == 0)
    {
        printf("Массив пуст\n");
        return VALUE_ERROR;
    }
    print(a, n);
    return SUCCESS;
}

