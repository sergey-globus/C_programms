/// Создание массива слов и массива слов без повторений

#include "arrmaker.h"

/// @brief создание списка введённых слов
/// @param lst список для заполнения
/// @param s введённая строка
/// @return количество слов
size_t list_words(char lst[][LEN_WORD], char s[])
{
    size_t count_words = 0;
    size_t i = 0;
    size_t word_len = 0;
    while (s[i] != '\0' && word_len < 17)
    {
        if (strchr("!?,-.;: \t\n", s[i]) == 0)
            lst[count_words][word_len++] = s[i];
        else
        {
            if (word_len != 0)
            {
                lst[count_words][word_len] = 0;
                count_words++;
            }
            word_len = 0;
        }
        i++;
    }
    if (word_len == 17)
        exit(WORD_ERROR);
    if (word_len != 0)
    {
        lst[count_words][word_len] = 0;
        count_words++;
    }

    return count_words;
}


/// @brief создание списка уникальных слов
/// @param unique список для заполнения
/// @param lst список слов введённой строки
/// @param count_of_slova количество слов введённых
/// @return длина списка уникальных строк
size_t uniqe_creator(char unique[][LEN_WORD], char lst[][LEN_WORD], size_t count_of_words)
{
    size_t count = 1;

    for (size_t i = 0; i < LEN_WORD; i++)
        unique[0][i] = lst[0][i];

    for (size_t i = 0; i < count_of_words; i++)
    {
        int flag = 0;
        for (size_t j = 0; j < count; j++)
            if (strcmp(unique[j], lst[i]) == 0)
            {
                flag = 1;
                break;
            }
        if (flag == 0)
            strcpy(unique[count++], lst[i]);
    }
    return count;
}
