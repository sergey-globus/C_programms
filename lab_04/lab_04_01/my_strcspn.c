/*!
 * выполняет поиск первого вхождения в строку string1 любого из символов строки string2, и возвращает
 * количество символов до найденного первого вхождения
 */
#include "my_strcspn.h"

/*!
  \str_where_2 - указатель на строку, в которой будет осуществляться определение длины участка, не содержащего символов указанных в строке str_from_2
  \str_from_2 - строка с набором символов, которые не должны входить в участок строки str_where_2
  \return - Длина начального участка строки, не содержащая символов указанных в аргументе str_from_2
*/
size_t my_strcspn(char *str_where_2, char *str_from_2)
{
    size_t lenn = 0;
    for (int i = 0; str_where_2[i] != '\0'; i++)
    {
        int flag = 0;
        for (int j = 0; str_from_2[j] != '\0'; j++)
        {
            if (str_where_2[i] == str_from_2[j])
                flag = 1;
        }
        if (flag == 1)
            return lenn;
        else
            lenn++;
    }
    return lenn;
}

/*!
 * \brief start_strcspn запуск тестировки
 * \return количество проваленных тестов
 */
int start_strcspn()
{
    char str_where_2[] = "2 111";
    char str_from_2[] = "1 3";
    char str_where_21[] = "222";
    char str_from_21[] = "22";
    char str_where_22[] = "wasd";
    char str_from_22[] = "h";
    char str_where_23[] = "oiuyt";
    char str_from_23[] = "y";
    
    int count = 0;
    if (my_strcspn(str_where_2, str_from_2) != strcspn(str_where_2, str_from_2))
        count++;
    if (my_strcspn(str_where_21, str_from_21) != strcspn(str_where_21, str_from_21))
        count++;
    if (my_strcspn(str_where_22, str_from_22) != strcspn(str_where_22, str_from_22))
        count++;
    if (my_strcspn(str_where_23, str_from_23) != strcspn(str_where_23, str_from_23))
        count++;
    return count;
}
