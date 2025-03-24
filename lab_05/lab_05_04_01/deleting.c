#include <stdio.h>
#include "deleting.h"

/*!
 * \brief average - среднее значение
 * \param arr - массив
 * \param c - количество элементов в массиве
 * \return среднее значение
 */
float average(struct student arr[], int c)
{
    int sum = 0;
    for (int i = 0; i < c; i++)
        for (int j = 0; j < GRADES; j++)
            sum += arr[i].grades[j];
    return (float)sum / (float)(c * GRADES);
}
/*!
 * \brief deleting - удаление элементов с позицией pos
 * \param arr - массив
 * \param c - количество элементов
 * \param pos - индекс
 */
void deleting(struct student arr[], int *c, int pos)
{
    for (int i = pos; i < (*c) - 1; i++)
        copy(&arr[i], &arr[i + 1]);
    (*c)--;
}
/*!
 * \brief deleting_below_average - удаление студентов с оценками ниже среднего
 * \param arr - массив
 * \param c - количество элементов в массиве
 */
void deleting_below_average(struct student arr[], int *c)
{
    float a = average(arr, *c);
    float cur_sum = 0;
    for (int i = 0; i < (*c); i++)
    {
        cur_sum = 0;
        for (int j = 0; j < GRADES; j++)
            cur_sum += arr[i].grades[j];
        if ((cur_sum / GRADES) < a)
        {
            deleting(arr, c, i);
            i--;
        }
    }
}
