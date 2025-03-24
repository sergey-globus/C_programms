/// \brief Ввод строки

#include "in.h"

/// @brief Ввод строки
/// @param strz строка для заполнения
void input(char *strz)
{
    size_t i = 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < MAX_STR_LEN - 1)
            strz[i++] = ch;
        else
            exit(BUFFER_ERROR);
    strz[i] = '\0';
}