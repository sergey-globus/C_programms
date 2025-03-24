#include "../inc/create_arr.h"
#include "../inc/sort.h"
#include "../inc/print.h"
#include "../inc/key.h"
#include "../inc/fill_arr.h"
#include "../inc/check_file.h"

/*!
 * Требуется написать программу, которая, будучи вызванной из командной строки:
 * app.exe IN_FILE OUT_FILE [f]
 * где IN_FILE — имя файла с входными данными, OUT_FILE — имя файла с выходными
 * данными, f — запрос фильтрации перед сортировкой;
 * 1. Считает количество элементов, записанных в файле.
 * 2. Выделяет память под соответствующее количество элементов.
 * 3. Читает файл ещё раз, заполняя динамический массив.
 * 4. Если указан параметр f, вызывает функцию-фильтр.
 * 5. Сортирует массив с новыми элементами с помощью назначенного преподава-
 * телем алгоритма сортировки.
 * 6. Записывает элементы отсортированного массива в текстовый файл.
 *
 * Вариант сортировки - Обменом (метод пузырька).
 * Вариант фильтрации - В массиве остаются элементы, которые больше среднего арифметического всех
 * элементов массива.
 */

/// Основная функция
int main(int argc, char **argv)
{
    int code_exit = SUCCESS;
    int n = 0;
    int *pb = NULL, *pe, *pb_new = NULL, *pe_new;
    FILE *in_file;
    FILE *out_file;

    /// Проверка количества аргументов командной строки
    if (argc == NUM_PARAM || argc == NUM_PARAM_WITH_FILTR)
    {
        /// Открываем файлы
        in_file = fopen(argv[NAME_IN_FILE], "r");
        if (in_file == NULL)
        {
            code_exit = FILE_ERROR;
        }
        
        if (code_exit == SUCCESS)
        {
            out_file = fopen(argv[NAME_OUT_FILE], "w");
            if (out_file == NULL)
            {
                fclose(in_file);
                code_exit = FILE_ERROR;
            }
        }

        /// Считаем количество чисел в файле
        if (code_exit == SUCCESS)
            code_exit = check_file(in_file, &n);

        /// Создаем динасмический массив
        if (code_exit == SUCCESS)
            create_arr(&pb, &pe, n, &code_exit);

        /// Запоняем динамический массив
        if (code_exit == SUCCESS)
        {
            rewind(in_file);
            fill_arr(in_file, pb, pe);
        }

        /// Проверка аргумента фильтрации
        if (code_exit == SUCCESS && argc == NUM_PARAM_WITH_FILTR && strcmp(argv[PARAM_FILTR], "f") != 0)
        {
            code_exit = PARAM_FILTR_ERROR;
            free(pb);
        }
        
        /// Фильтрация при наличии параметра
        if (code_exit == SUCCESS && argc == NUM_PARAM_WITH_FILTR)
        {
            code_exit = key(pb, pe, &pb_new, &pe_new);
            free(pb);
            pb = pb_new;
            pe = pe_new;
        }

        /// Сортировка
        if (code_exit == SUCCESS)
            mysort(pb, pe - pb, sizeof(int), compar_int);

        /// Вывод в файл
        if (code_exit == SUCCESS)
            print(out_file, pb, pe);

        /// Освободим память
        if (code_exit == SUCCESS)
            free(pb);

        /// Закроем файлы
        if (code_exit != FILE_ERROR)
        {
            fclose(in_file);
            fclose(out_file);
        }
    }
    else
    {
        code_exit = PARAM_ERROR;
    }

    return code_exit;
}

