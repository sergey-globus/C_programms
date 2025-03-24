#ifndef INPUT_H
#define INPUT_H

#include "const.h"

void read(FILE *file, float ***data, int n, int m, int *code_exit);
int input(float ***data, char *matrix, int *n, int *m);

#endif
