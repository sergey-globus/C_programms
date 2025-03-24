#ifndef INPUT_H
#define INPUT_H

#include "const.h"

node_t *create_node(void *data, size_t size);
node_t *add_end(node_t *head, node_t *new_elem);
int input(FILE *f, node_t **head);

#endif
