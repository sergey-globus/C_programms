/// \brief Создание списка слов для итоговой строки

#include "wordlistcreator.h"

/// @brief Разбиение строки на слова
/// @param wordlist список слов
/// @param str строка для разбиения
/// @return количество слов
size_t arrmaker(char wordlist[][MAX_WORD_LEN], char str[])
{
    size_t word_amount = 0;
    char *token = strtok(str, "!?;-:., \t\0\n");
    while (token != NULL)
    {
        if (strlen(token) > 16)
            exit(LEN_WORD_ERROR);
        for (size_t i = 0; i < MAX_WORD_LEN; i++)
        {
            if (i < strlen(token))
                wordlist[word_amount][i] = token[i];
            else
                wordlist[word_amount][i] = 0;
        }
        word_amount++;
        token = strtok(NULL, "!?;-:., \t\0\n");
    }
    return word_amount;
}

/// @brief удаление вхождений первой буквы
/// @param elem указатель на текущее слово
void deleter(char *elem)
{
    int f = 1;
    char sym = elem[0];
    while (elem[f]) 
    {
        if (elem[f] == sym) 
            for (int j = f; (elem[j] = elem[j + 1]); ++j);
        else
            ++f;
    }
}

/// @brief создание списка слов без вхождений последнего
/// @param finallst итоговый список
/// @param lastword указатель на последнее слово
/// @param wordlist искомый список
/// @param word_amount кол-во введённых слов
void no_last_lst(char finallst[][MAX_WORD_LEN], char *lastword, char wordlist[][MAX_WORD_LEN], size_t word_amount)
{
    size_t new_len = 0;
    for (size_t i = 0; i < word_amount; i++)
        if (strcmp(lastword, wordlist[i]) != 0)
        {
            strcpy(finallst[new_len], wordlist[i]);
            deleter(finallst[new_len++]);
        }
}