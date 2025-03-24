
#ifndef WORDLISTCREATOR_H
#define WORDLISTCREATOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 17 ///< максимальная длина слова

#define LEN_WORD_ERROR 4 ///< если длина слова больше 16

size_t arrmaker(char wordlist[][MAX_WORD_LEN], char str[]);
void no_last_lst(char finallst[][MAX_WORD_LEN], char *lastword, char wordlist[][MAX_WORD_LEN], size_t word_amount);
void deleter(char *elem);

#endif
