#ifndef CONST_H
#define CONST_H

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_PARAMS 3

#define FILE_NAME 1
#define NUMBER 2

#define PARAM_ERROR 1
#define FILE_ERROR 2
#define STRUCT_ERROR 3
#define EMPTY_ERROR 4
#define MEMORY_ERROR 5
#define SUCCESS 0

struct goods
{
    char *name;
    int sale;
};

#endif
