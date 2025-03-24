#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "student_related.h"

#ifndef DELETING_H
#define DELETING_H
float average(struct student arr[], int c);
void deleting(struct student arr[], int *c, int pos);
void deleting_below_average(struct student arr[], int *c);
#endif

