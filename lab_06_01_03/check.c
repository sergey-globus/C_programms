#include "check.h"

int check_number(char *str, double *number)
{
    int code_exit = 0;
    char *endptr; /// указатель на символ после числа
    *number = strtod(str, &endptr); /// преобразование параметра в веществееное число
    /// в случае успешного преобразования endptr будет указывать на нулевой символ
    if (*endptr != '\0')
        code_exit = PARAM_ERROR;
    return code_exit;
}
