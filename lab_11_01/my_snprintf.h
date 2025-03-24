#ifndef MY_SNPRINTF
#define MY_SNPRINTF

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int int_len(int num);
int x_len(long num);
char x_transfer(long num);
int my_snprintf(char *str, size_t size, const char *format, ...);

#endif
