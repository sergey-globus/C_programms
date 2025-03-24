#include "../inc/check_file.h"

int check_file(FILE *f, int *n)
{
    int code_exit = SUCCESS;
    int number;
    while (fscanf(f, "%d", &number) == 1)
        (*n)++;
    if (!feof(f))
    {
       code_exit = DATA_FILE_ERROR;
    }

    if (code_exit == SUCCESS)
        if (*n == 0)
            code_exit = EMPTY_FILE;
    return code_exit;
}
