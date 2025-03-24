#include "../inc/solution.h"
#include "../inc/allocate_data.h"

int triangular_form(float **mtr, int n, int m)
{
    int code_exit = SUCCESS;
    int j;
    float max = 0;
    int max_j;
    float eps = 1E-6;
    float *temp;
    float ratio;
    
    /// Приводим матрицу к верхне-треугольному виду
    for (int i = 0; i < n && code_exit == SUCCESS; i++)
    {
        max = 0;
        /// Найдем максимальный по модулю элемент, находящийся под mtr[i][i]
        for (j = i; j < n; j++)
            if (fabsf(mtr[j][i]) > max)
            {
                max = fabsf(mtr[j][i]);
                max_j = j;
            }

        /// Проверка
        if (max < eps)
            code_exit = INF_SOL_ERROR;

        /// Поменяем строку с этим элементом c i-той строкой местами
        if (code_exit == SUCCESS)
            if (j != i)
            {
                temp = mtr[max_j];
                mtr[max_j] = mtr[i];
                mtr[i] = temp;
            }

        /// Выполним прямой ход метода Гаусса, чтобы обнулить элементы под mtr[i][i]
        if (code_exit == SUCCESS)
            for (j = i + 1; j < n; j++)
                if (fabsf(mtr[j][i]) > eps)
                {
                    ratio = mtr[j][i] / mtr[i][i];
                    for (int k = 0; k < m; k++)
                        mtr[j][k] -= mtr[i][k] * ratio;
                }
    }
    return code_exit;
}

float matrix_sol(float **mtr, int n, int m, int i)
{
    float mtr_sol;

    /// Вычтем из строки все члены после mtr[i][i]
    for (int j = i + 1; j < n; j++)
    {
        mtr[i][m - 1] -= mtr[i][j];
        mtr[i][j] = 0;
    }

    /// Найдем i-тое решение
    mtr_sol = mtr[i][m - 1] / mtr[i][i];

    /// Подставим найденное решение в остальные строки
    for (int j = 0; j < i; j++)
        mtr[j][i] *= mtr_sol;

    return mtr_sol;
}

int solution(float **mtr, int n, int m, float ***mtr_sol)
{
    int code_exit = SUCCESS;

    /// Проверка параметров матриц
    if (m != n + 1)
        code_exit = SOL_ERROR;

    /// Приводим матрицу к верхне-треугольному виду
    if (code_exit == SUCCESS)
        code_exit = triangular_form(mtr, n, m);

    /// Выделяем память
    if (code_exit == SUCCESS)
    {
        *mtr_sol = allocate_data(n, 1);
        if (*mtr_sol == NULL)
            code_exit = MEMORY_ERROR;
    }

    /// Найдем решение СЛАУ
    if (code_exit == SUCCESS)
        for (int i = n - 1; i >= 0; i--)
            (*mtr_sol)[i][0] = matrix_sol(mtr, n, m, i);

    return code_exit;
}
