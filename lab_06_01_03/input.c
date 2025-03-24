#include "input.h"

int input(FILE *f, struct goods *arr, int *n)
{
    int code_exit = 0;
    if (fscanf(f, "%d", n) != 1)
        code_exit = STRUCT_ERROR;
    if (code_exit == 0 && (*n <= 0 || *n > MAX_GOODS))
        code_exit = STRUCT_ERROR;

    int i = 0;
    if (code_exit == 0)
        while (fscanf(f, "%25s %d", arr[i].name, &arr[i].sale) == 2)
        {
            if (arr[i].sale <= 0)
                code_exit = STRUCT_ERROR;
            i++;
        }
    if (code_exit == 0 && !feof(f))
        code_exit = STRUCT_ERROR;
    if (code_exit == 0 && *n != i)
        code_exit = STRUCT_ERROR;
    return code_exit;
}
