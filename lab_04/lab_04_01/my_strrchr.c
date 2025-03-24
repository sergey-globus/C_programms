/*!
 * поиск последнего вхождения символа в строку
 */
#include "my_strrchr.h"


/*!
  \str_where_3 - указатель на строку, в которой будет осуществляться поиск с конца
  \ch - код искомого символа
  \return - Указатель на искомый символ, если он найден в строке str, иначе NULL
*/
char *my_strrchr(char *str_where_3, int ch)
{
    size_t lenn = strlen(str_where_3);
    char *result = NULL;
    for (size_t i = 0; i <= lenn; i++)
        if (str_where_3[i] == ch)
            result = &str_where_3[i];
    return result;
}

/*!
 * \brief start_strrchr запуск тестировки
 * \return количество проваленных тестов
 */
int start_strrchr()
{
    char str_where_4[] = "0123456789";
    int ch_1 = 's';
    char str_where_41[] = "abcd";
    int ch_11 = 'd';
    char str_where_42[] = "1 2 3 4 5 6 7 8 9 0";
    int ch_12 = '1';
    char str_where_43[] = "oiurytrrgb";
    int ch_13 = 'r';
    int count = 0;
    if (my_strrchr(str_where_4, ch_1) != strrchr(str_where_4, ch_1))
        count++;
    if (my_strrchr(str_where_41, ch_11) != strrchr(str_where_41, ch_11))
        count++;
    if (my_strrchr(str_where_42, ch_12) != strrchr(str_where_42, ch_12))
        count++;
    if (my_strrchr(str_where_43, ch_13) != strrchr(str_where_43, ch_13))
        count++;
    return count;
}
