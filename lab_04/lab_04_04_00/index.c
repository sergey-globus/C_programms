/// \brief Получение индекса первой цифры или точки в искомой строке

#include "index.h"

/// @brief поиск позиции первого вхождения цифры или точки в строку
/// @param str введённая строка
/// @return позиция первой цифры или буквы
size_t finder(char str[])
{
    for (size_t i = 0; i < strlen(str); i++)
        if (strchr("1234567890.", str[i]) != NULL)
            return i;
    return 500;
}