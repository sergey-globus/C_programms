#ifndef IN_H
#define IN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256 ///< максимальная длина строки
#define MAX_WORD_K 128 ///< максимальное количество слов
#define LEN_WORD 17 ///< максимальная длина слова

#define SUCCESS 0 ///< код успешного завершения работы программы
#define EMPTY_INPUT 1 ///< код при пустом вводе
#define NO_WORDS_ERROR 2 ///< код на случай если не ввели ни одного слова
#define BUFFER_ERROR 3  ///< переполнение буфера ввода

void input(char *strz);

#endif
