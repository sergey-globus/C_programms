#include "../inc/sort.h"

int compar_int(void *a, void *b)
{
    return *((int *) a) - *((int *) b);
}

void swap(char *first, char *second, size_t size)
{
    char temp[size];
    memcpy(temp, first, size);
    memcpy(first, second, size);
    memcpy(second, temp, size);
}

int mysort(void *pb, size_t n, size_t size, int (*compar)(void *a, void *b))
{
    int code_exit = SUCCESS;
    char *arr = (char *) pb;
    char *first, *second;
    if (n == 0)
        code_exit = EMPTY_FILE;
    if (code_exit == SUCCESS)
    {
        for (size_t i = 0; i < n - 1; i++)
            for (size_t j = 0; j < n - i - 1; j++)
            {
                first = arr + size * j;
                second = arr + size * (j + 1);
                if (compar(first, second) > 0)
                    swap(first, second, size);
            }
    }
    return code_exit;
}
