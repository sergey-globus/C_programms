#include "print.h"

int print(FILE *file)
{
    int x;
    if (fread(&x, sizeof(int), 1, file) != 1)
        return EMPTY;
    printf("%d ", x);
    while (fread(&x, sizeof(int), 1, file) == 1)
        printf("%d ", x);
    if (! feof(file))
        return NOT_NUM;
    printf("\n");
    return OK;
}
