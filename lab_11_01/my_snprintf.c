#include "my_snprintf.h"

int int_len(int num)
{
    int i = 1;
    for (; num / 10 > 0; i++)
        num /= 10;
    return i;
}

int x_len(long num)
{
    int i = 1;
    for (; num / 16 > 0; i++)
        num /= 16;
    return i;
}

char x_transfer(long num)
{
    char symbol;
    if (num == 10)
        symbol = 'a';
    else if (num == 11)
        symbol = 'b';
    else if (num == 12)
        symbol = 'c';
    else if (num == 13)
        symbol = 'd';
    else if (num == 14)
        symbol = 'e';
    else if (num == 15)
        symbol = 'f';
    else
        symbol = '0' + num;
    return symbol;
}

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list vl;
    va_start(vl, format);

    size_t j = 0;
    for (size_t i = 0; format[i]; i++)
        if (format[i] == '%' && format[i + 1] == 'd')
        {
            i++;
            int num = va_arg(vl, int);
            if (num < 0)
            {
                if (j < size)
                    str[j] = '-';
                j++;
                num = -num;
            }
            int len = int_len(num);
            int divider = 1;
            for (int i = 1; i < len; i++)
                divider *= 10;
            for (int i = 0; i < len; i++)
            {
                if (j < size)
                    str[j] = '0' + num / divider;
                j++;
                num = num % divider;
                divider /= 10;
            }
        }
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            i++;
            char *row = strdup(va_arg(vl, char *));
            for (int k = 0; row[k]; k++)
            {
                if (j < size)
                    str[j] = row[k];
                j++;
            }

            free(row);
        }
        else if (format[i] == '%' && format[i + 1] == 'l' && format[i + 2] == 'x')
        {
            i += 2;
            long num = va_arg(vl, long);
            if (num < 0)
            {
                if (j < size)
                    str[j] = '-';
                j++;
                num = -num;
            }
            int len = x_len(num);
            int divider = 1;
            for (int i = 1; i < len; i++)
                divider *= 16;
            for (int i = 0; i < len; i++)
            {
                if (j < size)
                    str[j] = x_transfer(num / divider);
                j++;
                num = num % divider;
                divider /= 16;
            }
        }
        else
        {
            if (j < size)
                str[j] = format[i];
            j++;
        }
    if (j < size)
        str[j] = '\0';
    else if (size > 0)
        str[size - 1] = '\0';

    va_end(vl);

    return j;
}
