#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lab_10_03_common/associative_array.h"

typedef struct node node_t;

struct node
{
    char *key;
    int num;
    node_t *next;
};

struct assoc_array_type
{
    node_t *head;
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t arr = NULL;
    arr = malloc(sizeof(struct assoc_array_type));
    if (arr)
        arr->head = NULL;
    return arr;
}

void assoc_array_destroy(assoc_array_t *arr)
{
    if (*arr)
        free(*arr);
    *arr = NULL;
}

assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    if (key == NULL || strcmp(key, "\n") == 0 || strcmp(key, "\0") == 0)
        return ASSOC_ARRAY_INVALID_PARAM;

    node_t *cur = arr->head;
    for (; cur; cur = cur->next)
        if (strcmp(key, cur->key) == 0)
            return ASSOC_ARRAY_KEY_EXISTS;

    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node)
        return ASSOC_ARRAY_MEM;

    new_node->key = strdup(key);
    new_node->num = num;
    new_node->next = NULL;

    if (arr->head)
    {
        cur = arr->head;
        while (cur->next)
            cur = cur->next;
        cur->next = new_node;
    }
    else
        arr->head = new_node;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (key == NULL || strcmp(key, "\n") == 0 || strcmp(key, "\0") == 0)
        return ASSOC_ARRAY_INVALID_PARAM;

    node_t *cur = arr->head;
    for (; cur; cur = cur->next)
        if (strcmp(cur->key, key) == 0)
        {
            *num = &cur->num;
            return ASSOC_ARRAY_OK;
        }

    return ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (strcmp(key, "\n") == 0 || strcmp(key, "\0") == 0)
        return ASSOC_ARRAY_INVALID_PARAM;

    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;

    node_t *prev = arr->head;
    node_t *cur = arr->head;
    node_t *next;
    for (; cur; prev = cur, cur = cur->next)
        if (strcmp(cur->key, key) == 0)
        {
            next = cur->next;
            free(cur->key);
            free(cur);
            if (cur == arr->head)
                arr->head = next;
            else
                prev->next = next;
            return ASSOC_ARRAY_OK;
        }

    return ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    node_t *next;
    if (arr->head)
        for (; arr->head; arr->head = next)
        {
            next = arr->head->next;
            free(arr->head->key);
            free(arr->head);
        }
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (arr == NULL || action == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;

    node_t *cur = arr->head;
    for (; cur; cur = cur->next)
        action(cur->key, &cur->num, param);
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (num == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;

    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;

    node_t *min = arr->head;
    node_t *cur = arr->head;
    for (; cur->next; cur = cur->next)
        if (strcmp(cur->next->key, min->key) < 0)
            min = cur->next;
    *num = &min->num;
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (num == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;

    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;

    node_t *max = arr->head;
    node_t *cur = arr->head;
    for (; cur->next; cur = cur->next)
        if (strcmp(cur->next->key, max->key) > 0)
            max = cur->next;
    *num = &max->num;
    return ASSOC_ARRAY_OK;
}
