#include "add_end.h"

void add_end(node_t **head, node_t *new_elem)
{
    node_t *cur = *head;
    if (cur == NULL)
        *head = new_elem;
    else
    {
        while (cur->next)
            cur = cur->next;
        cur->next = new_elem;
    }
}
