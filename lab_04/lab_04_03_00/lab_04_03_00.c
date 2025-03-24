/// \brief работа №4, задача №3, вариант №0
/// Ввод - строка
/// Вывод - строка со словами отличными от последнего в реверсивном порядке с удалёнными вхождениями первой буквы

#include "wordlistcreator.h"
#include "in.h"

/// @brief Основная функция
/// @return Код завершения
int main()
{
    char str[MAX_STR_LEN + 1]; ///< вводимая строка
    input(str);

    if (strchr("\n", str[0]) != 0)
        return EMPTY_INPUT;
    
    char wordlist[MAX_WORD_COUNT][MAX_WORD_LEN]; ///< список слов

    size_t word_amount = arrmaker(wordlist, str); ///< количество введённых слов
    
    char *lastword = wordlist[word_amount - 1];   ///< последнее слово
    size_t count_of_last = 1;  ///< количество слов таких же как и последнее

    for (size_t i = 0; i < word_amount - 1; i++)
        if (strcmp(lastword, wordlist[i]) == 0)
            count_of_last++;

    if (word_amount == count_of_last)
        return NO_WORD_BALANCE;

    char finallst[word_amount - count_of_last][MAX_WORD_LEN]; ///< список слов без таких как последнее и без него тоже
    no_last_lst(finallst, lastword, wordlist, word_amount);

    char real[MAX_STR_LEN + 1] = ""; ///< строка для вывода
    for (int i = word_amount - count_of_last - 1; i > -1; i--)
    {
        strcat(real, finallst[i]);
        if (i != 0)
            strcat(real, " ");
    }

    printf("Result: %s\n", real);
    return SUCCESS;
}