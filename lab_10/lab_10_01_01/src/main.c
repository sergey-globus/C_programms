#include "../inc/sorted_insert.h"
#include "../inc/sort.h"
#include "../inc/print.h"
#include "../inc/insert.h"
#include "../inc/input.h"
#include "../inc/free_data.h"
#include "../inc/find.h"
#include "../inc/comparator_scores.h"
#include "../inc/append.h"

int main(int argc, char **argv)
{
    int code_exit = SUCCESS;
    FILE *in_file_1;
    FILE *in_file_2;
    FILE *out_file;
    node_t *head_a = NULL;
    node_t *head_b = NULL;

    /// Проверка параметров командной строки
    if (argc == PARAMS_WITH_SORT && strcmp(argv[ACTION], "sort") == 0)
    {
        in_file_1 = fopen(argv[IN_FILE_1], "r");
        out_file = fopen(argv[OUT_FILE_WITH_SORT], "w");
        if (in_file_1 == NULL || out_file == NULL)
            code_exit = FILE_ERROR;
    }
    else if (argc == PARAMS && strcmp(argv[ACTION], "sort") != 0)
    {
        in_file_1 = fopen(argv[IN_FILE_1], "r");
        in_file_2 = fopen(argv[IN_FILE_2], "r");
        if (in_file_1 == NULL && in_file_2 != NULL)
        {
            fclose(in_file_1);
            code_exit = FILE_ERROR;
        }
        out_file = fopen(argv[OUT_FILE], "w");
        if (in_file_1 == NULL || in_file_2 == NULL || out_file == NULL)
            code_exit = FILE_ERROR;
    }
    else
        code_exit = PARAM_ERROR;

    /// Выполнение действия
    if (code_exit == SUCCESS && strcmp(argv[ACTION], "find") == 0)
    {
        /// Создание списков из данных в файлах
        code_exit = input(in_file_1, &head_a);
        if (code_exit == SUCCESS)
            if ((code_exit = input(in_file_2, &head_b)) != SUCCESS)
                free_data(head_a);
        /// Проверка на, что во втором списке только один элемент
        if (code_exit == SUCCESS)
            if (head_b->next != NULL)
            {
                free_data(head_a);
                free_data(head_b);
                code_exit = ELEM_ERROR;
            }
        /// Поиск элемента
        if (code_exit == SUCCESS)
        {
            if (find(head_a, head_b->data, comparator_subject) == NULL)
                fprintf(out_file, "Предмет не найден\n");
            else
                fprintf(out_file, "Предмет найден\n");
        }
    }
    else if (code_exit == SUCCESS && strcmp(argv[ACTION], "insert") == 0)
    {
        /// Создание списков из данных в файлах
        code_exit = input(in_file_1, &head_a);
        if (code_exit == SUCCESS)
            if ((code_exit = input(in_file_2, &head_b)) != SUCCESS)
                free_data(head_a);
        /// Проверка на, что во втором списке только один элемент
        if (code_exit == SUCCESS)
            if (head_b->next != NULL)
            {
                free_data(head_a);
                free_data(head_b);
                code_exit = ELEM_ERROR;
            }
        /// Вставляем элемент и выводим получившийся список
        if (code_exit == SUCCESS)
        {
            insert(&head_a, head_b, head_a);
            head_b = NULL;
            print(out_file, head_a);
        }
    }
    else if (code_exit == SUCCESS && strcmp(argv[ACTION], "append") == 0)
    {
        /// Создание списков из данных в файлах
        code_exit = input(in_file_1, &head_a);
        if (code_exit == SUCCESS)
            if ((code_exit = input(in_file_2, &head_b)) != SUCCESS)
                free_data(head_a);
        /// Добавление второго списка в конец первого и вывод получившегося списка
        if (code_exit == SUCCESS)
        {
            append(&head_a, &head_b);
            print(out_file, head_a);
        }
    }
    else if (code_exit == SUCCESS && strcmp(argv[ACTION], "sort") == 0)
    {
        /// Создание списка из данных в файле
        code_exit = input(in_file_1, &head_a);
        /// Сортировка и вывод
        if (code_exit == SUCCESS)
        {
            head_a = sort(head_a, comparator_scores);
            print(out_file, head_a);
        }
    }
    else if (code_exit == SUCCESS)
        code_exit = PARAM_ERROR;


    /// Освобождение памяти
    if (code_exit == SUCCESS)
    {
        free_data(head_a);
        free_data(head_b);
    }

    /// Закрываем файлы
    if (argc == PARAMS_WITH_SORT)
    {
        fclose(out_file);
        if (code_exit != FILE_ERROR)
            fclose(in_file_1);
    }
    else if (argc == PARAMS)
    {
        fclose(out_file);
        if (code_exit != FILE_ERROR)
        {
            fclose(in_file_1);
            fclose(in_file_2);
        }
    }

    return code_exit;
}
