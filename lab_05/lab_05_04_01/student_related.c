#include <stdio.h>
#include "student_related.h"

/*!
 * \brief print - вывод на экран массив структур
 * \param arr - массив структур
 * \param c - количество элементов в массиве
 */
void print(struct student arr[], int c)
{
    for (int i = 0; i < c; i++)
    {
        printf("%s\n%s\n", arr[i].surname, arr[i].name);
        for (int j = 0; j < GRADES; j++)
            printf("%u ", arr[i].grades[j]);
        printf("\n");
    }
}
/*!
 * \brief clear - очищает поле ввода
 * \param f - файл
 */
void clear(FILE *f)
{
    char c;
    int res;
    do
    {
        res = fscanf(f, "%c", &c);
    }
    while (res == 1 && c != '\n');
}
/*!
 * \brief input - чтение строк
 * \param s - куда записываем
 * \param f - откуда читаем
 * \param max_len - максимум, что мы можем прочитать
 * \return как прошло
 */
int input(char *s, FILE *f, int max_len)
{
    char ch;
    int i = 0;
    while ((ch = fgetc(f)) != '\n' && ch != EOF)
        if (i < max_len)
            s[i++] = ch;
        else
            return ERROR;
    if (i == 0)
        return ERROR;
    s[i] = 0;
    return SUCCESS;
}
/*!
 * \brief extracting - запись элементов из файла в массив
 * \param f - файл
 * \param arr - массив
 * \param c - количество элементов в массиве
 * \return - как прошло
 */
int extracting(FILE *f, struct student arr[], int *c)
{
    int i = 0;
    int x;
    while (!ferror(f))
    {
        if (input(arr[i].surname, f, SURNAME) != SUCCESS)
            return ERROR;
        if (input(arr[i].name, f, NAME) != SUCCESS)
            return ERROR;
        if (arr[i].surname[strlen(arr[i].surname) - 1] == '\n')
            arr[i].surname[strlen(arr[i].surname) - 1] = 0;
        if (arr[i].name[strlen(arr[i].name) - 1] == '\n')
            arr[i].name[strlen(arr[i].name) - 1] = 0;
        for (int j = 0; j < GRADES; j++)
            if (fscanf(f, "%d\n", &x) == 1 && (x >= 0))
                arr[i].grades[j] = x;
            else
                return ERROR;
        i++;
        if (feof(f) != 0)
            break;
    }
    (*c) = i;
    return SUCCESS;
}
/*!
 * \brief putting_back - запись элементов из массива в файл
 * \param f - файл
 * \param arr - массив
 * \param c - количество элементов в массиве
 */
void putting_back(FILE *f, struct student arr[], int c)
{
    for (int i = 0; i < c; i++)
    {
        fprintf(f, "%s\n%s\n%u %u %u %u\n", arr[i].surname, arr[i].name, arr[i].grades[0], arr[i].grades[1], arr[i].grades[2], arr[i].grades[3]);
    }
}
/*!
 * \brief copy - копирование структур
 * \param x - первая структура
 * \param y - вторая структура
 */
void copy(struct student *x, struct student *y)
{
    strcpy(x->surname, y->surname);
    strcpy(x->name, y->name);
    for (int j = 0; j < GRADES; j++)
        x->grades[j] = y->grades[j];
}
