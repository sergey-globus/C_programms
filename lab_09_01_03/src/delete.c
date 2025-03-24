#include "../inc/delete.h"

void delete(struct goods *arr, int *n, int k)
{
    for (int i = k; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;

    free(arr[k].name);
}
