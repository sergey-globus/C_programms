#include "../inc/action_multy.h"
#include "../inc/input.h"
#include "../inc/print.h"
#include "../inc/multyplication.h"

int action_multy(int argc, char **argv)
{
    float **mtr_multy;
    float **mtr_1;
    float **mtr_2;
    int n1, m1;
    int n2, m2;
    int code_exit = SUCCESS;

    /// Запишем информацию из файлов в матрицы
    if (code_exit == SUCCESS)
        code_exit = input(&mtr_1, argv[FIRST_MTR], &n1, &m1);
    if (code_exit == SUCCESS)
    {
        code_exit = input(&mtr_2, argv[SECOND_MTR], &n2, &m2);
        if (code_exit != SUCCESS)
            free(mtr_1);
    }

    /// Умножение матриц
    if (code_exit == SUCCESS)
    {
        code_exit = multyplication(mtr_1, n1, m1, mtr_2, n2, m2, &mtr_multy);
        free(mtr_1);
        free(mtr_2);
    }

    /// Вывод результирующей матрицы
    if (code_exit == SUCCESS)
    {
        code_exit = print(mtr_multy, n1, m2, argv[OUT_FILE]);
        free(mtr_multy);
    }
    
    return code_exit;
}
