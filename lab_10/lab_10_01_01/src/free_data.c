#include "../inc/free_data.h"

void free_data(node_t *head)
{
    node_t *next = head;
    for (; head; head = next)
    {
        next = head->next;
        free(((struct base *) head->data)->subject);
        free(head->data);
        free(head);
    }
}
