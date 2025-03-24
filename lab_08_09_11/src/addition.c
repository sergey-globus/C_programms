#include "../inc/addition.h"
#include "../inc/allocate_data.h"

int addition(float **mtr_1, int n1, int m1, float **mtr_2, int n2, int m2, float ***mtr_sum)
{
    int code_exit = SUCCESS;

    /// Проверка параметров матриц
    if (!(n1 == n2 && m1 == m2))
        code_exit = ADD_ERROR;

    /// Выделяем память
    if (code_exit == SUCCESS)
    {
        *mtr_sum = allocate_data(n1, m1);
        if (*mtr_sum == NULL)
            code_exit = MEMORY_ERROR;
    }

    /// Сложение матриц
    if (code_exit == SUCCESS)
        for (int i = 0; i < n1; i++)
            for (int j = 0; j < m1; j++)
                (*mtr_sum)[i][j] = mtr_1[i][j] + mtr_2[i][j];

    return code_exit;
}
