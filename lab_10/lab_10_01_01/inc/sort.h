#ifndef SORT_H
#define SORT_H

#include "const.h"

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

#endif
