#include "print.h"

void print(node_t *head)
{
    node_t *cur = head;
    for (; cur; cur = cur->next)
        printf("%d ", cur->power);
    printf("L\n");
}
