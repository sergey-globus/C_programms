#ifndef FIND_H
#define FIND_H

#include "const.h"

int comparator_subject(const void *a, const void *b);
node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

#endif
