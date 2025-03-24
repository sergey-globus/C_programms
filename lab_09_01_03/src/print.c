#include "../inc/print.h"

void print(struct goods *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i].name);
        printf("%d\n", arr[i].sale);
    }
}
