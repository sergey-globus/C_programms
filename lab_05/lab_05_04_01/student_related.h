#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ERROR -1
#define CANNOT_OPEN_FILE 1
#define TOO_LONG 2
#define EXTRACTING_GONE_WRONG 3
#define REWRITING_GONE_WRONG 4
#define SUCCESS 0
#define NAME 10
#define SURNAME 25
#define GRADES 4
#define STUDENTS 100
#define WRONG_PARAMS 53

#ifndef STUDENT_RELATED_H
#define STUDENT_RELATED_H
struct student
{
    char surname[SURNAME + 1]; ///<- фвмилия студента
    char name[NAME + 1]; ///<- имя
    uint32_t grades[GRADES]; ///<- оценка
};
void print(struct student arr[], int c);
void clear(FILE *f);
int read_line(char *s, FILE *f, int max_len);
int extracting(FILE *f, struct student arr[], int *c);
void putting_back(FILE *f, struct student arr[], int c);
void copy(struct student *x, struct student *y);
#endif
