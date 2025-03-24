/// \brief Модуль служит для различных проверок введённой строки и ip-адреса на валидность

#include "check_str.h"

/// @brief проверка строки на наличие инородных символов
/// @param str введённая строка
/// @return код ошибки
int checker_input(char str[])
{
    for (size_t i = 0; i < strlen(str); i++)
        if (strchr("1234567890\t\v\f\r .", str[i]) == NULL)
            return 1;
    return 0;
}

/// @brief Проверка ip-адреса на валидность
/// @param ip строка с ip-адресом
/// @param len длина ip-адреса
/// @return код ошибки
int checker_ip(char ip[], size_t len)
{
    if (strstr(ip, "..") != NULL) /// проверка повторяющихся точек
        return 1;
    if (strchr(".", ip[0]) != NULL) /// проверка что точка стоит на первом месте
        return 1;
    if (strchr(".", ip[len - 1]) != NULL) /// проверяет что точка стоит на последнем месте
        return 1;
    
    for (size_t i = 0; ip[i] != '\0'; i++) /// проверка вхождения пробельных символов в ip
        if (strchr(" \t\v\f\r", ip[i]) != NULL)
            return 1;

    int dot_count = 0;
    for (size_t i = 0; ip[i] != '\0'; i++) /// проверка кол-ва входящих точек
        if (strchr(".", ip[i]) != NULL)
            dot_count++;
    if (dot_count != 3)
        return 1;

    int lenn = 0;
    char str[MAX_NUMBER_LEN + 1];
    for (size_t i = 0; i < len + 1; i++)
        if (strchr(".", ip[i]) == NULL)
            str[lenn++] = ip[i];
        else
        {
            if (lenn > 3)
                return 1;
            str[lenn] = 0;
            if (strtol(str, NULL, 10) > MAX_IN_IP)
                return 1;
            lenn = 0;
        }
    return 0;
}