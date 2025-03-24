#ifndef CHECK_STR_H
#define CHECK_STR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IN_IP 255 ///< максимальное число в ip-адресе
#define MAX_NUMBER_LEN 16 ///< максимальная длина числа в ip-адресе

int checker_input();
int checker_ip();

#endif
