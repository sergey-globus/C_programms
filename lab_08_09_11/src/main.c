#include "../inc/action_solution.h"
#include "../inc/action_multy.h"
#include "../inc/action_addition.h"
#include "../inc/allocate_data.h"
#include "../inc/solution.h"
#include "../inc/print.h"
#include "../inc/multyplication.h"
#include "../inc/input.h"
#include "../inc/addition.h"

/*!
 * \brief Лабораторная работа 8, вариант 9
 * app.exe action mtr_1.txt [mtr_2.txt] res.txt
 * Возможные значения action:
 * 1. a — сложение;
 * 2. m — умножение;
 * 3. o — Решение СЛАУ методом Гаусса с выбором ведущего
 * элемента по столбцу (для неё mtr_2.txt не указывается)
 */
 
 /// Основная функция
int main(int argc, char **argv)
{
    int code_exit = SUCCESS;

    if (argc == PARAM_FOR_A && strcmp(argv[ACTION], "a") == 0)
        code_exit = action_addition(argc, argv);
    else if (argc == PARAM_FOR_M && strcmp(argv[ACTION], "m") == 0)
        code_exit = action_multy(argc, argv);
    else if (argc == PARAM_FOR_O && strcmp(argv[ACTION], "o") == 0)
        code_exit = action_solution(argc, argv);
    else
        code_exit = PARAM_ERROR;

    return code_exit;
}
