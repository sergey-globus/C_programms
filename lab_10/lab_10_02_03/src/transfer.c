#include "transfer.h"
#include "create_node.h"
#include "add_end.h"

bool is_simple(int number)
{
    double square_number = sqrt(number);
    for (int i = 2; i <= square_number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int next_simple(int number)
{
    while (!is_simple(number + 1))
        number++;
    return number + 1;
}

int power_divider(int *number, int divider)
{
    int i = 0;
    while (*number % divider == 0)
    {
        i++;
        *number /= divider;
    }
    return i;
}

node_t *transfer(int number)
{
    node_t *head = NULL;
    int tmp;

    if (number == 1)
        add_end(&head, create_node(0));
    else
        for (int i = 2; number != 1; i = next_simple(i))
        {
            tmp = power_divider(&number, i);
            add_end(&head, create_node(tmp));
        }

    return head;
}
