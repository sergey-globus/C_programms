#ifndef CONST_H
#define CONST_H

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PARAMS 5
#define ACTION 1
#define IN_FILE_1 2
#define IN_FILE_2 3
#define OUT_FILE 4

#define PARAMS_WITH_SORT 4
#define OUT_FILE_WITH_SORT 3

#define SUCCESS 0
#define FILE_ERROR 1
#define PARAM_ERROR 2
#define STRUCT_ERROR 3
#define MEMORY_ERROR 4
#define EMPTY_ERROR 5
#define ELEM_ERROR 6

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

struct base
{
    char *subject;
    int scores;
};

#endif
