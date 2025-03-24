#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "student_related.h"

#ifndef FORMING_H
#define FORMING_H
bool starts_with_str2(char str1[], char str2[]);
int rewriting_sub_str2(struct student arr[], int c, struct student arr2[], int *c2, char str2[]);
#endif
