/*!
 * Требуется написать программу, совершающую действие над двоичным файлом целых 
 * чисел int в ответ на вызов с ключом:
 * 1. создавать файл и заполнять его случайными числами (аргументы в произволь-
 * ной форме, например, app.exe c number file; создание не проверяется :));
 * 2. выводить числа из файла на экран (app.exe p file);
 * 3. упорядочивать числа в файле (app.exe s file).
 */

#include <stdio.h>
#include "create.h"
#include "print.h"
#include "sort.h"
#include "const.h"

/// Основная функция
int main(int argc, char *argv[])
{
    FILE *file;
    int rc;

    if (argc < 3)
        return NO_ARGS;

    if (strcmp(argv[1], "c") == 0)
    {
        if (argc != 4)
            return NO_ARGS;

        file = fopen(argv[3], "wb");
        if (create(file, argv[2]) == NOT_NUM)
        {
            fclose(file);
            return NOT_NUM;
        }
        fclose(file);
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        if (argc != 3)
            return NO_ARGS;
        file = fopen(argv[2], "rb");
        if (file == NULL)
            return NO_OPEN;
        rc = print(file);
        if (rc != OK)
        {
            fclose(file);
            return rc;
        }
        fclose(file);
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        if (argc != 3)
            return NO_ARGS;
        file = fopen(argv[2], "r+b");
        if (file == NULL)
            return NO_OPEN;
        rc = sort(file);
        if (rc != OK)
        {
            fclose(file);
            return rc;
        }
        fclose(file);
    }
    else
        return ERR_DO;
    return OK;
}
