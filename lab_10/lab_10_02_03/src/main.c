#include "transfer.h"
#include "sqr.h"
#include "print.h"
#include "mul.h"
#include "free_data.h"
#include "div.h"
#include "create_node.h"
#include "add_end.h"

int main()
{
    int code_exit = SUCCESS;
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_res = NULL;
    char action[4];
    int number_1, number_2;

    /// Ввод действия
    scanf("%3s", action);
    action[3] = '\0';
    /// Ввод чисел
    if (strcmp(action, "out") == 0 || strcmp(action, "sqr") == 0)
    {
        if (scanf("%d", &number_1) != 1 || number_1 <= 0)
            code_exit = INPUT_ERROR;
    }
    else if (strcmp(action, "mul") == 0 || strcmp(action, "div") == 0)
    {
        if (scanf("%d%d", &number_1, &number_2) != 2 || number_1 <= 0 || number_2 <= 0)
            code_exit = INPUT_ERROR;
        if (code_exit == SUCCESS && number_1 < number_2)
            code_exit = DIV_ERROR;
    }
    else
        code_exit = INPUT_ERROR;

    /// Выполнение действия
    if (code_exit == SUCCESS && strcmp(action, "out") == 0)
    {
        head_1 = transfer((number_1));
        print(head_1);
    }
    else if (code_exit == SUCCESS && strcmp(action, "sqr") == 0)
    {
        head_1 = transfer((number_1));
        sqr(&head_1);
        print(head_1);
    }
    else if (code_exit == SUCCESS && strcmp(action, "mul") == 0)
    {
        head_1 = transfer((number_1));
        head_2 = transfer((number_2));
        head_res = mul(head_1, head_2);
        print(head_res);
    }
    else if (code_exit == SUCCESS && strcmp(action, "div") == 0)
    {
        head_res = int_div(number_1, number_2);
        print(head_res);
    }

    /// Освобождение памяти
    free_data(head_1);
    free_data(head_2);
    free_data(head_res);

    return code_exit;
}
