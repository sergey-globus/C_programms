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
};

struct assoc_array_type
{
    node_t *a;
    int len;
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t arr = NULL;
    arr = malloc(sizeof(struct assoc_array_type));
    if (arr)
    {
        arr->a = NULL;
        arr->len = 0;
    }
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

    for (int i = 0; i < arr->len; i++)
        if (strcmp(arr->a[i].key, key) == 0)
            return ASSOC_ARRAY_KEY_EXISTS;

    (arr->len)++;
    arr->a = realloc(arr->a, arr->len * sizeof(struct node));
    if (!arr->a)
        return ASSOC_ARRAY_MEM;

    arr->a[arr->len - 1].key = strdup(key);
    arr->a[arr->len - 1].num = num;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (key == NULL || strcmp(key, "\n") == 0 || strcmp(key, "\0") == 0)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (int i = 0; i < arr->len; i++)
        if (strcmp(arr->a[i].key, key) == 0)
        {
            *num = malloc(sizeof(int));
            if (*num == NULL)
                return ASSOC_ARRAY_MEM;
            **num = arr->a[i].num;
            return ASSOC_ARRAY_OK;
        }

    return ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (strcmp(key, "\n") == 0 || strcmp(key, "\0") == 0)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (int i = 0; i < arr->len; i++)
        if (strcmp(arr->a[i].key, key) == 0)
        {
            free(arr->a[i].key);
            for (int j = i; j < arr->len - 1; j++)
                arr->a[j] = arr->a[j + 1];
            arr->len--;
            arr->a = realloc(arr->a, arr->len * sizeof(struct node));
            return ASSOC_ARRAY_OK;
        }

    return ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    for (int i = 0; i < arr->len; i++)
        free(arr->a[i].key);
    free(arr->a);
    arr->len = 0;
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (arr == NULL || action == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    for (int i = 0; i < arr->len; i++)
        action(arr->a[i].key, &arr->a[i].num, param);
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (num == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;

    if (arr->len == 0)
        return ASSOC_ARRAY_NOT_FOUND;

    node_t min = arr->a[0];
    for (int i = 1; i < arr->len; i++)
        if (strcmp(arr->a[i].key, min.key) < 0)
            min = arr->a[i];
    *num = malloc(sizeof(int));
    if (*num == NULL)
        return ASSOC_ARRAY_MEM;
    **num = min.num;
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (num == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;

    if (arr->len == 0)
        return ASSOC_ARRAY_NOT_FOUND;

    node_t max = arr->a[0];
    for (int i = 1; i < arr->len; i++)
        if (strcmp(arr->a[i].key, max.key) > 0)
            max = arr->a[i];
    *num = malloc(sizeof(int));
    if (*num == NULL)
        return ASSOC_ARRAY_MEM;
    **num = max.num;
    return ASSOC_ARRAY_OK;
}
