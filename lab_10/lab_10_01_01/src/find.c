#include "../inc/find.h"

int comparator_subject(const void *a, const void *b)
{
    return strcmp(((struct base*) a)->subject, ((struct base*) b)->subject);
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    node_t *node = NULL;
    for (; head; head = head->next)
        if (comparator(data, head->data) == 0)
            node = head;
    return node;
}
