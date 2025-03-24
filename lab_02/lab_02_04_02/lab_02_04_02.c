#include <stdio.h>
#include <stddef.h>

#define N 10

size_t min(int *a, size_t n, size_t k)
{
    size_t index_min = k;
    int min_el = a[k];
    for (size_t i = k + 1; i < n; i++)
        if (a[i] < min_el)
        {
            min_el = a[i];
            index_min = i;
        }
    return index_min;
}
void sort(int *a, size_t n)
{
    size_t index_min;
    int c;
    for (size_t i = 0; i < n - 1; i++)
    {
        index_min = min(a, n, i);
        c = a[index_min];
        a[index_min] = a[i];
        a[i] = c;
    }
}
void print(int *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main(void)
{
    int a[N + 1];
    int n = 0;
    int i = 0;
    int flag_end = 0;
    while (scanf("%d", a + i) != 0)
    {
        if (n == N)
        {
            flag_end = 1;
            break;
        }
        i++;
        n++;
    }
    if (n == 0)
    {
        printf("Массив пуст\n");
        return 1;
    }
    sort(a, n);
    print(a, n);
    if (flag_end)
        return 100;
    else
        return 0;
}

