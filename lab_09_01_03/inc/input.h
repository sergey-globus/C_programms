#ifndef INPUT_H
#define INPUT_H

#include "const.h"

int read(FILE *f, struct goods **arr, int *code_exit);
int input(FILE *f, struct goods **arr, int *n);

#endif
