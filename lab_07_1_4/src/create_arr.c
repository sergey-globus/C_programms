#include "../inc/create_arr.h"

void create_arr(int **pb, int **pe, int n, int *code_exit)
{
    *pb = malloc(n * sizeof(int));
    if (*pb == NULL)
        *code_exit = CREATE_MASSIVE_ERROR;
    *pe = *pb + n;
}
