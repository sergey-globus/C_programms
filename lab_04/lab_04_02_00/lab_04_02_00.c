/// \brief Лабораторная работа №4, задача №2, вариант №0
/// Ввод - строка
/// Вывод - пары слово - кол-во раз его встречи в исходной строке


#include "arrmaker.h"
#include "out.h"
#include "in.h"


/// @brief Основная функция
/// @return код успешного завершения программы
int main(void)
{
    char str[MAX_LEN + 1]; ///< строка которая вводится
    input(str);

    if (strchr("\n", str[0]) != 0)
        return EMPTY_INPUT;
    
    char lst[MAX_WORD_K][LEN_WORD]; ///< список слов введённой строки
    size_t count_of_slova = list_words(lst, str);

    if (count_of_slova == 0)
        return NO_WORDS_ERROR;

    char unique[MAX_WORD_K][LEN_WORD]; ///< список уникальных элементов
    size_t unique_k = uniqe_creator(unique, lst, count_of_slova); ///< кол-во уникальных элементов

    printf("Result: ");
    countprint(unique, lst, unique_k, count_of_slova);

    return SUCCESS;
}
