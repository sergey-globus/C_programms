#include "../inc/input.h"
#include "../inc/allocate_data.h"

void read(FILE *file, float ***data, int n, int m, int *code_exit)
{
    int i = 0, j = 0;
    float number;
    while (fscanf(file, "%f", &number) == 1 && i < n)
    {
        (*data)[i][j] = number;
        j++;
        if (j == m)
        {
            j = 0;
            i++;
        }
    }
    if (!(i == n && feof(file)))
    {
        *code_exit = DATA_FILE_ERROR;
        free(*data);
    }
}

int input(float ***data, char *matrix, int *n, int *m)
{
    int code_exit = SUCCESS;

    /// Открываем файл
    FILE *file = fopen(matrix, "r");
    if (!file)
        code_exit = FILE_ERROR;

    /// Читаем из файла число строк и число столбцов матрицы
    if (code_exit == SUCCESS)
        if (fscanf(file, "%d %d", n, m) != 2)
            code_exit = DATA_FILE_ERROR;

    /// Проверка параметров матрицы
    if (code_exit == SUCCESS)
        if (*n <= 0 || *m <= 0)
            code_exit = DATA_FILE_ERROR;

    /// Выделяем память
    if (code_exit == SUCCESS)
    {
        *data = allocate_data(*n, *m);
        if (*data == NULL)
            code_exit = MEMORY_ERROR;
    }

    /// Инициализируем матрицу числами из файла
    if (code_exit == SUCCESS)
        read(file, data, *n, *m, &code_exit);

    /// Закрываем файл
    if (code_exit != FILE_ERROR)
        fclose(file);

    return code_exit;
}
