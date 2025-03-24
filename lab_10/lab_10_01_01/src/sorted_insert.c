#include "../inc/sorted_insert.h"
#include "../inc/comparator_scores.h"

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (*head == NULL)
        *head = element;
    else
    {
        if (comparator(element->data, (*head)->data) < 0)
        {
            element->next = *head;
            *head = element;
        }
        else
        {
            node_t *cur = *head;
            while (cur->next && comparator(element->data, (cur->next)->data) >= 0)
                cur = cur->next;
            element->next = cur->next;
            cur->next = element;
        }
    }
}
