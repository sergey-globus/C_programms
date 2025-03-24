#include "../inc/print.h"

void print(FILE *f, int *pb, int *pe)
{
    int *pcur = pb;
    while (pcur < pe)
    {
        fprintf(f, "%d ", *pcur);
        pcur++;
    }
}
