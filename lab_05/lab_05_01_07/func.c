/// Определение количества локальных максимумов

#include "func.h"

/*!
 * \brief process Определение количества локальных максимумов в последовательности
 * \param f файл, где находятся числа (stdin)
 * \param cnt количество локальных максимумов
 * \return как все прошло
 */
int process(FILE *f, int *cnt)
{
    int value;
    int counter = 0;
    int error = 0;
    int prev;
    int flag = 0;
    while (!feof(f) && fscanf(f, "%d", &value) == 1)
    {
        error++;
        if (counter == 0)
        {
            counter++;
            prev = value;
            continue;
        }

        if (flag == 0)
        {
            if (prev < value)
                flag = 1;
        }
        else
        {
            if (prev > value)
            {
                flag = 0;
                *cnt = *cnt + 1;
            }
        }
        prev = value;
    }
    if (counter == 0)
        return ERROR;
    if (error == 0 || error == 1 || error == 2)
        return IO_ERROR;
    return OK;
}
