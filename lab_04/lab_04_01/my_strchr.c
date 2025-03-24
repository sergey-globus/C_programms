/*!
 * находит первое вхождение символа в str или возвращает NULL , если такой не найден
 */
#include "my_strchr.h"

/*!
  \str_where_3 - указатель на строку, в которой будет осуществляться поиск
  \ch - индекс искомого символа
  \return - Указатель на искомый символ, если он найден в строке str, иначе NULL
*/
char *my_strchr(char *str_where_3, int ch)
{
    size_t lenn = strlen(str_where_3);

    for (size_t i = 0; i <= lenn; i++)
        if (str_where_3[i] == ch)
            return &str_where_3[i];
    return NULL;
}


/*!
 * \brief start_strchr запуск тестировки
 * \return количество проваленных тестов
 */
int start_strchr()
{
    char str_where_3[] = "0123456789";
    int ch = 'd';
    char str_where_31[] = "abcd";
    int ch1 = 'a';
    char str_where_32[] = "1 2 3 4 5 6 7 8 9 0";
    int ch2 = '5';
    char str_where_33[] = "abcdef";
    int ch3 = 'f';
    char str_where_34[] = "0";
    int ch4 = 'a';
    int count = 0;
    if (my_strchr(str_where_3, ch) != strchr(str_where_3, ch))
        count++;
    if (my_strchr(str_where_31, ch1) != strchr(str_where_31, ch1))
        count++;
    if (my_strchr(str_where_32, ch2) != strchr(str_where_32, ch2))
        count++;
    if (my_strchr(str_where_33, ch3) != strchr(str_where_33, ch3))
        count++;
    if (my_strchr(str_where_34, ch4) != strchr(str_where_34, ch4))
        count++;
    return count;
}
