#include "../inc/insert.h"

void insert(node_t **head, node_t *elem, node_t *before)
{
    node_t *cur = *head;
    if (before == *head)
    {
        elem->next = *head;
        *head = elem;
    }
    else
        for (; cur; cur = cur->next)
            if (cur->next == before)
            {
                cur->next = elem;
                elem->next = before;
                return;
            }
}
