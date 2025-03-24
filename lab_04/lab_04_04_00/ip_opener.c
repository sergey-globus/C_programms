/// \brief Создание строки с ip-адресом

#include "ip_opener.h"

/// @brief создание строки с ip-адресом
/// @param ip строка для заполнения
/// @param s введённая строка
/// @param first_index_int индекс первого вхождения цифры в ведённую строку
/// @return длина ip-адреса
size_t creator(char *ip, char *s, size_t first_index_int)
{
    size_t ip_len = 0;

    for (size_t i = first_index_int; i < strlen(s); i++)
        if (strchr("\t ", s[i]) == NULL)
            ip[ip_len++] = s[i];
        else
            for (size_t j = i; j < strlen(s); j++)
                if (strchr("\t \v\f\r", s[j]) == NULL)
                    return 500;
        
    if (ip_len > IP_LEN - 1)
        return 500;
    ip[ip_len] = 0;
    return ip_len;
}