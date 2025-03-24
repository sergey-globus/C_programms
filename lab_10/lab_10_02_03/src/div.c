#include "div.h"
#include "transfer.h"

node_t *int_div(int number_1, int number_2)
{
    node_t *head_res;
    int dividing = number_1 / number_2;
    head_res = transfer(dividing);
    return head_res;
}
