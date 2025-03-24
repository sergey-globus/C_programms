#include "../inc/print.h"
int print(float **mtr, int n, int m, char *res_file)
{
    int code_exit = SUCCESS;

    /// Открываем файл
    FILE *file = fopen(res_file, "w");
    if (!file)
        code_exit = FILE_ERROR;

    /// Вывод матрицы в файл
    if (code_exit == SUCCESS)
    {
        fprintf(file, "%d %d\n", n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                fprintf(file, "%f ", mtr[i][j]);
            fprintf(file, "\n");
        }
    }

    /// Закрываем файл
    if (code_exit != FILE_ERROR)
        fclose(file);

    return code_exit;
}
