#ifndef IN_H
#define IN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0 ///< код успешного завершения программы
#define EMPTY_INPUT 1 ///< пустой ввод
#define NO_WORD_BALANCE 2 ///< если все слова равны последнему
#define BUFFER_ERROR 3 ///< переполнение буфера

#define MAX_STR_LEN 256 ///< максимальная длина строки
#define MAX_WORD_LEN 17 ///< максимальная длина слова
#define MAX_WORD_COUNT 128 ///< максимальное количество слов

void input(char strz[MAX_STR_LEN + 1]);

#endif
