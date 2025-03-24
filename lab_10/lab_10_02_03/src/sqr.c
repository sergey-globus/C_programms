#include "sqr.h"

void sqr(node_t **head)
{
    node_t *cur = *head;
    for (; cur; cur = cur->next)
        cur->power *= 2;
}
