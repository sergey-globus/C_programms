#include "../inc/print.h"
#include "../inc/input.h"
#include "../inc/free_data.h"
#include "../inc/delete.h"
#include "../inc/compare.h"
#include "../inc/checkNumber.h"

/*!
 * Требуется написать программу, которая, будучи вызванной из командной строки:
 * app.exe FILE P
 * где FILE — имя файла, P — значение цены;
 * 1. считывает информацию о продуктах в массив.
 * 2. Выводит на экран информацию о продуктах, цена которых ниже значения P.
 */

/// Основная функция
int main(int argc, char **argv)
{
    struct goods *arr = NULL;
    int n; /// количество товаров
    int code_exit = SUCCESS;
    double number;

    /// Проверка количества параметров
    if (argc != NUM_PARAMS)
        code_exit = PARAM_ERROR;

    /// Проверка второго параметра на число
    if (code_exit == 0)
        code_exit = check_number(argv[NUMBER], &number);

    /// Открываем файл
    FILE *f;
    if (code_exit == 0)
    {
        f = fopen(argv[FILE_NAME], "r");
        if (f == NULL)
            code_exit = FILE_ERROR;
    }

    /// пернесем информацию о товарах в массив
    if (code_exit == SUCCESS)
        code_exit = input(f, &arr, &n);

    /// Удалим элементы, не соответствующие условию
    if (code_exit == SUCCESS)
        for (int i = n - 1; i >= 0; i--)
            if (compare(arr[i], number))
                delete(arr, &n, i);

    /// выведем на экран нужную информацию
    if (code_exit == SUCCESS)
        print(arr, n);

    /// закроем файл
    if (code_exit != PARAM_ERROR && code_exit != FILE_ERROR)
        fclose(f);

    /// Освободим память
    if (code_exit == 0)
        free_data(arr, n);

    return code_exit;
}
