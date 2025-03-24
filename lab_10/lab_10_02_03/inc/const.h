#ifndef CONST_H
#define CONST_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define INPUT_ERROR 1
#define DIV_ERROR 2

typedef struct node node_t;

struct node
{
    int power;
    node_t *next;
};

#endif
