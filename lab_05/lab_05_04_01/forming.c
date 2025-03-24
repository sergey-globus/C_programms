#include <stdio.h>
#include "forming.h"

/*!
 * \brief starts_with_str2 - флаг, показывающий, начинается ли фамилия студента с заданной подстроки 
 * \param str1 - фамилия студента
 * \param str2 - заданная подстрока
 * \return true, если да, иначе false
 */
bool starts_with_str2(char str1[], char str2[])
{
    char *istr;
    istr = strstr(str1, str2);
    if ((istr - str1) == 0)
        return true;
    else
        return false;
}
/*!
 * \brief rewriting_sub_str2 - формирует новый массив со студентами, чьи фамилии начинаются со str2
 * \param arr - студенты
 * \param c - количество студентов
 * \param arr2 - студенты, чьи фамилии начинаются со str2
 * \param c2 - их количество
 * \param str2 - строка
 * \return - как все прошло
 */
int rewriting_sub_str2(struct student arr[], int c, struct student arr2[], int *c2, char str2[])
{
    for (int i = 0; i < c; i++)
    {
        if (starts_with_str2(arr[i].surname, str2))
        {
            copy(&arr2[*c2], &arr[i]);
            (*c2)++;
        }
    }
    if ((*c2) == 0)
        return ERROR;
    return SUCCESS;
}
