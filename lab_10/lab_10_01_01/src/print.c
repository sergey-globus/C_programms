#include "../inc/print.h"

void print(FILE *f, node_t *head)
{
    node_t *cur = head;
    for (; cur; cur = cur->next)
    {
        fprintf(f, "%s", ((struct base *) cur->data)->subject);
        fprintf(f, "%d\n", ((struct base *) cur->data)->scores);
    }
}
