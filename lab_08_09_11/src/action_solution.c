#include "../inc/action_solution.h"
#include "../inc/input.h"
#include "../inc/print.h"
#include "../inc/solution.h"

int action_solution(int argc, char **argv)
{
    float **mtr_sol;
    float **mtr_1;
    int n1, m1;
    int code_exit = SUCCESS;

    /// Запишем информацию из файла в матрицу
    if (code_exit == SUCCESS)
        code_exit = input(&mtr_1, argv[FIRST_MTR], &n1, &m1);

    /// Найдем решение СЛАУ
    if (code_exit == SUCCESS)
    {
        code_exit = solution(mtr_1, n1, m1, &mtr_sol);
        free(mtr_1);
    }

    /// Вывод столбца решений
    if (code_exit == SUCCESS)
    {
        code_exit = print(mtr_sol, n1, 1, argv[OUT_FILE_FOR_O]);
        free(mtr_sol);
    }
    
    return code_exit;
}
