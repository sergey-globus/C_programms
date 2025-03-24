#include "../inc/append.h"

void append(node_t **head_a, node_t **head_b)
{
    if (*head_a)
    {
        node_t *cur = *head_a;
        while (cur->next)
            cur = cur->next;
        cur->next = *head_b;
    }
    else
        *head_a = *head_b;

    *head_b = NULL;
}
