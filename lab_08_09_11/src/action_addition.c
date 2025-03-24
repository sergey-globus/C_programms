#include "../inc/action_addition.h"
#include "../inc/input.h"
#include "../inc/print.h"
#include "../inc/addition.h"

int action_addition(int argc, char **argv)
{
    float **mtr_sum;
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

    /// Сложение матриц
    if (code_exit == SUCCESS)
    {
        code_exit = addition(mtr_1, n1, m1, mtr_2, n2, m2, &mtr_sum);
        free(mtr_1);
        free(mtr_2);
    }

    /// Вывод результирующей матрицы
    if (code_exit == SUCCESS)
    {
        code_exit = print(mtr_sum, n1, m1, argv[OUT_FILE]);
        free(mtr_sum);
    }
    
    return code_exit;
}
