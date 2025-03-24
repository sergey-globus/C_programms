/*!
 * Требуется написать программу, совершающую действие в ответ на вызов с ключом:
 * (a) Сортировка студентов по фамилии, студенты с одинаковыми фамилиями
 * должны быть упорядочены по имени. Результат выводится на экран.
 * Запуск программы для обработки текстового файла:  ./app.exe st FILE
 * (b) Вывод информации о студентах, фамилии которых начинаются с заданной
 * подстроки, в другой файл.
 * Запуск программы для обработки текстового файла:   ./app.exe ft FILE_SRC FILE_DST SUBSTR
 * (c) Удаление из файла студентов, чей средний балл меньше среднего балла
 * по всему файлу. Результат записывается в тот же файл.
 * Запуск программы для обработки текстового файла:  ./app.exe dt FILE
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "student_related.h"
#include "sorting.h"
#include "forming.h"
#include "deleting.h"

/// Основная функция
int main(int argc, char **argv)
{
    if (argc > 2)
    {
        bool one_of_options = false;
        if (strcmp(argv[1], "st") == 0 && argc == 3)
        {
            one_of_options = true;
            FILE *f;
            f = fopen(argv[2], "r");
            if (f == NULL)
            {
                return CANNOT_OPEN_FILE;
            }
            struct student arr[STUDENTS];
            int c = 0;
            if (extracting(f, arr, &c) == ERROR)
            {
                return EXTRACTING_GONE_WRONG;
            }
            fclose(f);
            sort(arr, c);
            print(arr, c);
        }
        if (strcmp(argv[1], "ft") == 0 && argc == 5)
        {
            one_of_options = true;
            FILE *f;
            f = fopen(argv[2], "r");
            if (f == NULL)
            {
                return CANNOT_OPEN_FILE;
            }
            struct student arr[STUDENTS];
            int c = 0;
            if (extracting(f, arr, &c) == ERROR)
            {
                return EXTRACTING_GONE_WRONG;
            }
            fclose(f);
            struct student arr2[STUDENTS];
            int c2 = 0;
            if (rewriting_sub_str2(arr, c, arr2, &c2, argv[4]) == ERROR)
            {
                return REWRITING_GONE_WRONG;
            }
            f = fopen(argv[3], "w");
            if (f == NULL)
            {
                return CANNOT_OPEN_FILE;
            }
            putting_back(f, arr2, c2);
            fclose(f);
        }
        if (strcmp(argv[1], "dt") == 0 && argc == 3)
        {
            one_of_options = true;
            FILE *f;
            f = fopen(argv[2], "r");
            if (f == NULL)
            {
                return CANNOT_OPEN_FILE;
            }
            struct student arr[STUDENTS];
            int c = 0;
            if (extracting(f, arr, &c) == ERROR)
            {
                return EXTRACTING_GONE_WRONG;
            }
            fclose(f);
            deleting_below_average(arr, &c);
            f = fopen(argv[2], "w");
            if (f == NULL)
            {
                return CANNOT_OPEN_FILE;
            }
            putting_back(f, arr, c);
            fclose(f);
        }
        if (one_of_options)
            return SUCCESS;
        else
        {
            return WRONG_PARAMS;
        }
    }
    else
    {
        return WRONG_PARAMS;
    }
}
