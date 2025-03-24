#include "../inc/input.h"
#include "../inc/free_data.h"

node_t *create_node(void *data, size_t size)
{
    node_t *elem = malloc(sizeof(node_t));
    elem->data = malloc(size);
    if (!elem->data)
        free(elem);

    if (elem->data && elem)
    {
        memcpy(elem->data, data, size);
        elem->next = NULL;
    }

    return elem;
}

node_t *add_end(node_t *head, node_t *new_elem)
{
    node_t *cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = new_elem;
    return head;
}

int input(FILE *f, node_t **head)
{
    int code_exit = SUCCESS;
    char *read_subject = NULL;
    char *read_scores = NULL;
    size_t len = 0;
    struct base tmp;

    /// Создание головы
    if (code_exit == SUCCESS && getline(&read_subject, &len, f) != -1 && getline(&read_scores, &len, f) != -1)
    {
        /// Проверка значений
        if (strcmp(read_subject, "\n") == 0)
            code_exit = STRUCT_ERROR;
        if (sscanf(read_scores, "%d", &tmp.scores) != 1 || tmp.scores < 0 || tmp.scores > 100)
            code_exit = STRUCT_ERROR;
        /// Заполнение названия предмета
        if (code_exit == SUCCESS && asprintf(&tmp.subject, "%s", read_subject) == -1)
            code_exit = STRUCT_ERROR;
        /// Создание узла списка
        if (code_exit == SUCCESS && (*head = create_node(&tmp, sizeof(struct base))) == NULL)
            code_exit = MEMORY_ERROR;
    }
    else
        code_exit = EMPTY_ERROR;

    /// Добавление остальных элементов в список
    node_t *cur;
    while (code_exit == SUCCESS && getline(&read_subject, &len, f) != -1 && getline(&read_scores, &len, f) != -1)
    {
        /// Проверка значений
        if (strcmp(read_subject, "\n") == 0)
            code_exit = STRUCT_ERROR;
        if (sscanf(read_scores, "%d", &tmp.scores) != 1 || tmp.scores < 0 || tmp.scores > 100)
            code_exit = STRUCT_ERROR;
        /// Заполнение названия предмета
        if (code_exit == SUCCESS && asprintf(&tmp.subject, "%s", read_subject) == -1)
            code_exit = STRUCT_ERROR;
        /// Создание узла списка
        if (code_exit == SUCCESS && (cur = create_node(&tmp, sizeof(struct base))) == NULL)
            code_exit = MEMORY_ERROR;
        /// Добавление элемента в список
        if (code_exit == SUCCESS)
            *head = add_end(*head, cur);
    }

    if (code_exit != SUCCESS)
        free_data(*head);

    free(read_subject);
    free(read_scores);
    return code_exit;
}
