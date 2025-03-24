/*!
 * \brief Лабораторная работа №4, задача №1
 * Требуется самостоятельно реализовать аналоги следующих строковых функций:
 * 0. strpbrk;
 * 1. strspn;
 * 2. strcspn
 * 3. strchr;
 * 4. strrchr.
 */

#include "my_strchr.h"
#include "my_strcspn.h"
#include "my_strpbrk.h"
#include "my_strrchr.h"
#include "my_strspn.h"

/// @brief Основная фукнция
int main()
{
    int count_strpbrk = start_strpbrk();

    int count_strspn = start_strspn();

    int count_strcspn = start_strcspn();

    int count_strchr = start_strchr();

    int count_strrchr = start_strrchr();

    printf("%d\n", count_strchr + count_strcspn + count_strpbrk + count_strrchr + count_strspn);
    return SUCCESS;
}
