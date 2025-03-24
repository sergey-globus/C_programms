#include "../inc/free_data.h"

void free_data(struct goods *arr, int n)
{
    for (int i = 0; i < n; i++)
        free(arr[i].name);
    free(arr);
}
