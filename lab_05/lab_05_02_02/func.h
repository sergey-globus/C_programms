#ifndef FUNC_H
#define FUNC_H

#define OK 0
#define ARG_ERROR 1
#define IO_ERROR 2
#define EMPTY 3

int average(FILE *f, int *cnt, double *middler);
void dispersion(FILE *f, double *disperse, double middler);
#endif
