#include "create_node.h"

node_t *create_node(int number)
{
    node_t *elem = NULL;
    elem = malloc(sizeof(node_t));

    if (elem)
    {
        elem->power = number;
        elem->next = NULL;
    }

    return elem;
}
