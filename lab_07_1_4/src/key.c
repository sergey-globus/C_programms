#include "../inc/key.h"

float average_value(int *pb, int *pe)
{
    int *pcur = pb;
    int numbers = 0;
    int sum = 0;
    float average;
    while (pcur < pe)
    {
        sum += *pcur;
        numbers++;
        pcur++;
    }
    average = (float) sum / numbers;
    return average;
}

int key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst)
{
    int code_exit = SUCCESS;
    int n = 0;
    int *pcur_src;
    int *pcur_dst;

    /// Находим среднее арифметическое
    float average = average_value(pb_src, pe_src);

    /// Находим количество элементов массива, больше среднего арифметического
    pcur_src = pb_src;
    while (pcur_src < pe_src)
    {
        if (*pcur_src > average)
            n++;
        pcur_src++;
    }
    if (n == 0)
        code_exit = EMPTY_FILTR_FILE;

    /// Создаем динамический массив
    if (code_exit == SUCCESS)
    {
        *pb_dst = malloc(n * sizeof(int));
        if (*pb_dst == NULL)
        {
            code_exit = CREATE_MASSIVE_ERROR;
        }
        *pe_dst = *pb_dst + n;
    }

    /// Копируем элементы, которые больше среднего арифметического, из старого массива в новый
    if (code_exit == SUCCESS)
    {
        pcur_dst = *pb_dst;
        pcur_src = pb_src;
        while (pcur_src < pe_src)
        {
            if (*pcur_src > average)
            {
                *pcur_dst = *pcur_src;
                pcur_dst++;
            }
            pcur_src++;
        }
    }
    return code_exit;
}
