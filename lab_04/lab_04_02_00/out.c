/// \brief вывод результатов работы программы

#include "out.h"

/// @brief вывод результатов работы программы
/// @param unique список уникальных слов
/// @param lst список всех слов
/// @param unique_k кол-во уникальных слов
/// @param count_of_slova кол-во всех слов
void countprint(char unique[][LEN_WORD], char lst[][LEN_WORD], size_t unique_k, size_t count_of_slova)
{
    for (size_t i = 0; i < unique_k; i++)
    {
        int counter = 0;
        for (size_t j = 0; j < count_of_slova; j++)
            if (strcmp(unique[i], lst[j]) == 0)
                counter++;
        printf("%s %d\n", unique[i], counter);
    }
}