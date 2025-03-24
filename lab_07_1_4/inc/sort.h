#ifndef SORT_H
#define SORT_H

#include "const.h"

int compar_int(void *a, void *b);
void swap(char *first, char *second, size_t size);
int mysort(void *pb, size_t n, size_t size, int (*compar)(void *a, void *b));

#endif
