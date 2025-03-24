/*!
 * определение максимальной длины участка строки, содержащего только указанные символы
 */
#include "my_strspn.h"

/*!
  \str_where_1 - указатель на строку, в которой ведется поиск.
  \str_from_1 - указатель на строку с набором символов, которые должны входить в участок строки str_where_1
  \return - Длина начального участка строки, содержащая только символы, указанные в аргументе str_from_1
*/
size_t my_strspn(char *str_where_1, char *str_from_1)
{
    size_t lenn = 0;
    for (int i = 0; str_where_1[i] != '\0'; i++)
    {
        int flag = 0;
        for (int j = 0; str_from_1[j] != '\0'; j++)
        {
            if (str_where_1[i] == str_from_1[j])
            {
                flag = 1;
                lenn++;
            }
        }
        if (lenn == 0 || flag == 0)
            return lenn;
    }
    return lenn;
}

/*!
 * \brief start_strspn запуск тестировки
 * \return количество проваленных тестов
 */
int start_strspn()
{
    char str_where_1[] = "0123456789";
    char str_from_1[] = "9";
    char str_where_11[] = "wasd";
    char str_from_11[] = "wasd";
    char str_where_12[] = "ab cd";
    char str_from_12[] = "b a";
    char str_where_13[] = "9";
    char str_from_13[] = "9";

    int count = 0;
    if (my_strspn(str_where_1, str_from_1) != strspn(str_where_1, str_from_1))
        count++;
    if (my_strspn(str_where_11, str_from_11) != strspn(str_where_11, str_from_11))
        count++;
    if (my_strspn(str_where_12, str_from_12) != strspn(str_where_12, str_from_12))
        count++;
    if (my_strspn(str_where_13, str_from_13) != strspn(str_where_13, str_from_13))
        count++;
    return count;
}
