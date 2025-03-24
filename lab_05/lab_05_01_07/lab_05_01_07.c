/*!
 * \brief Лабораторная работа 5, задание 1, вариант 7
 * Определить количество локальных максимумов в последовательности
 */

#include <stdio.h>
#include "func.h"

/// Основная функция
int main(int argc, char **argv)
{
    int cnt = 0;
    int rc = process(stdin, &cnt);
    if (rc == ERROR)
        return ERROR;
    if (rc == IO_ERROR)
        return IO_ERROR;
    printf("%d\n", cnt);
    return OK;
}
