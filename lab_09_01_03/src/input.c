#include "../inc/input.h"
#include "../inc/free_data.h"

int read(FILE *f, struct goods **arr, int *code_exit)
{
    int i = 0;
    char *read_name = NULL;
    char *read_sale = NULL;
    size_t len = 0;
    while (*code_exit == SUCCESS && getline(&read_name, &len, f) != -1 && getline(&read_sale, &len, f) != -1)
    {
        /// Выделяем память для новой структуры
        if (*code_exit == SUCCESS)
        {
            *arr = realloc(*arr, (i + 1) * sizeof(struct goods));
            if (!*arr)
            {
                *code_exit = MEMORY_ERROR;
                free_data(*arr, i);
            }
        }

        /// Убираем \n в конце строки имени
        if (*code_exit == SUCCESS && strcmp(read_name, "\n") == 0)
        {
            *code_exit = STRUCT_ERROR;
            free_data(*arr, i);
        }
        if (*code_exit == SUCCESS)
            sscanf(read_name, "%s", read_name);

        /// Заполняем структуру
        if (*code_exit == SUCCESS)
            if (asprintf(&(*arr)[i].name, "%s", read_name) == -1)
            {
                *code_exit = STRUCT_ERROR;
                free_data(*arr, i);
            }
        if (*code_exit == SUCCESS)
            if (sscanf(read_sale, "%d", &(*arr)[i].sale) != 1)
            {
                *code_exit = STRUCT_ERROR;
                free_data(*arr, i + 1);
            }
            
        /// Проверка на отрицательную цену
        if (*code_exit == SUCCESS)
            if ((*arr)[i].sale < 0)
            {
                *code_exit = STRUCT_ERROR;
                free_data(*arr, i + 1);
            }
        
        i++;
    }

    free(read_name);
    free(read_sale);
    
    return i;
}

int input(FILE *f, struct goods **arr, int *n)
{
    int code_exit = SUCCESS;
    int number_goods;

    /// Читаем количество товаров из первой строки
    if (fscanf(f, "%d", n) != 1)
        code_exit = STRUCT_ERROR;
    if (code_exit == SUCCESS && *n <= 0)
        code_exit = STRUCT_ERROR;

    /// Читаем символ \n
    if (code_exit == SUCCESS)
        fgetc(f);

    /// Читаем имя и цену товаров
    if (code_exit == SUCCESS)
        number_goods = read(f, arr, &code_exit);

    /// Проверка количетва товаров с n
    if (code_exit == SUCCESS && *n != number_goods)
    {
        code_exit = STRUCT_ERROR;
        free_data(*arr, number_goods);
    }
    return code_exit;
}
