#include "../inc/multyplication.h"
#include "../inc/allocate_data.h"

float matrix_multyply(float **mtr_1, float **mtr_2, int m1, int i, int j)
{
    float multy = 0;
    for (int k = 0; k < m1; k++)
        multy += (mtr_1[i][k] * mtr_2[k][j]);
    return multy;
}

int multyplication(float **mtr_1, int n1, int m1, float **mtr_2, int n2, int m2, float ***mtr_multy)
{
    int code_exit = SUCCESS;

    /// Проверка параметров матриц
    if (m1 != n2)
        code_exit = MULTY_ERROR;

    /// Выделяем память
    if (code_exit == SUCCESS)
    {
        *mtr_multy = allocate_data(n1, m2);
        if (*mtr_multy == NULL)
            code_exit = MEMORY_ERROR;
    }

    /// Умножение матриц
    if (code_exit == SUCCESS)
        for (int i = 0; i < n1; i++)
            for (int j = 0; j < m2; j++)
                (*mtr_multy)[i][j] = matrix_multyply(mtr_1, mtr_2, m1, i, j);

    return code_exit;
}
