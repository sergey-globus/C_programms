#ifndef SORTED_INSERT_H
#define SORTED_INSERT_H

#include "const.h"

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

#endif
