#ifndef IN_H
#define IN_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0 ///< код успешного завершения программы
#define BUFFER_ERROR 10 ///< код переполнения буфера

#define MAX_STR_LEN 256 ///< максимальная длина строки
#define MAX_LEN_WORD 17 ///< максимальная длина слова
#define IP_LEN 16 ///< максимальная длина ip-адреса

void input();

#endif
