#include <stdio.h>
#include "sorting.h"

/*!
 * \brief sort - сортировка студентов по алфавиту
 * \param arr - студенты
 * \param c - количество студентов
 */
void sort(struct student arr[], int c)
{
    struct student temp;
    for (int i = 1; i < c; i++)
        for (int j = 0; j < c - i; j++)
            if (strcmp(arr[j].surname, arr[j + 1].surname) > 0)
            {
                copy(&temp, &arr[j]);
                copy(&arr[j], &arr[j + 1]);
                copy(&arr[j + 1], &temp);
            }
            else
            {
                if (strcmp(arr[j].surname, arr[j + 1].surname) == 0)
                {
                    if (strcmp(arr[j].name, arr[j + 1].name) > 0)
                    {
                        copy(&temp, &arr[j]);
                        copy(&arr[j], &arr[j + 1]);
                        copy(&arr[j + 1], &temp);
                    }
                }
            }
}
