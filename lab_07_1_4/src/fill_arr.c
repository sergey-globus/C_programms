#include "../inc/fill_arr.h"

void fill_arr(FILE *f, int *pb, int *pe)
{
    int *pcur = pb;
    while (pcur < pe)
        if (fscanf(f, "%d", pcur) == 1)
            pcur++;
}
