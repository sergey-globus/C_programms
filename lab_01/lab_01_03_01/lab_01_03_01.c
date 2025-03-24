#include <stdio.h>

int main(void)
{
    float v1, v2;
    float t1, t2;
    float v, t;
    printf("Введите обьём воды в первой ёмкости: ");
    scanf("%f", &v1);
    printf("Введите температуру воды в первой ёмкости: ");
    scanf("%f", &t1);
    printf("Введите обьём воды во второй ёмкости: ");
    scanf("%f", &v2);
    printf("Введите температуру воды во второй ёмкости: ");
    scanf("%f", &t2);
    v = v1 + v2;
    t = (t1 * v1 + t2 * v2) / v;
    printf("%f\n", v);
    printf("%f\n", t);
    return 0;
}

