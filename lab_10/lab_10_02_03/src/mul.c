#include "mul.h"
#include "create_node.h"
#include "add_end.h"

node_t *mul(node_t *head_1, node_t *head_2)
{
    node_t *head_res = NULL;
    int num_1, num_2;

    while (head_1 || head_2)
    {
        num_1 = head_1 ? head_1->power : 0;
        num_2 = head_2 ? head_2->power : 0;
        add_end(&head_res, create_node(num_1 + num_2));
        if (head_1)
            head_1 = head_1->next;
        if (head_2)
            head_2 = head_2->next;
    }

    return head_res;
}
