/*!
 * поиск первого вхождения в строку символа из указанного множества
 */
#include "my_strpbrk.h"

/*!
  \str_where - строка где производится поиск
  \str_from - строка символов для поиска
  \return - Указатель на первый найденный в строке str_where символ из множества символов строки str_from
*/
char *my_strpbrk(char *str_where, char *str_from)
{
    int indexx = 0;
    int flag = 0;
    for (int i = 0; str_from[i] != '\0'; i++)
        for (int j = 0; str_where[j] != '\0'; j++)
        {
            if (str_where[j] == str_from[i])
            {
                if (flag == 0)
                {
                    indexx = j;
                    flag = 1;
                }
                else
                {
                    if (j < indexx)
                        indexx = j;
                }
            }
        }
    if (indexx == 0 && flag == 0)
        return NULL;
    char *id = &str_where[indexx];
    return id;
}


/*!
 * \brief start_strpbrk запуск тестировки
 * \return количество проваленных тестов
 */
int start_strpbrk()
{
    char str_where[] = "12";
    char str_from[] = "34";
    char str_where1[] = "389a";
    char str_from1[] = "sdfa";
    char str_where2[] = "frgh";
    char str_from2[] = "frgh";
    char str_where3[] = "mn l";
    char str_from3[] = "z ";
    int count = 0;

    if (my_strpbrk(str_where, str_from) != strpbrk(str_where, str_from))
        count++;
    if (my_strpbrk(str_where1, str_from1) != strpbrk(str_where1, str_from1))
        count++;
    if (my_strpbrk(str_where2, str_from2) != strpbrk(str_where2, str_from2))
        count++;
    if (my_strpbrk(str_where3, str_from3) != strpbrk(str_where3, str_from3))
        count++;
    
    return count;
}
