#include "../inc/sort.h"
#include "../inc/sorted_insert.h"
#include "../inc/comparator_scores.h"

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head)
    {
        node_t *next;
        node_t *elem = head->next;
        head->next = NULL;
        for (; elem; elem = next)
        {
            next = elem->next;
            sorted_insert(&head, elem, comparator);
        }
    }
    return head;
}
