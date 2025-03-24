#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b;
    double phi;
    double s;
    const double pi = 3.1415926536;
    printf("Введите оснивания трапеции: ");
    scanf("%lf%lf", &a, &b);
    printf("Введите угол: ");
    scanf("%lf", &phi);
    phi = phi * pi / 180;
    s = (a + b) * tan(phi) * fabs(b - a) / 4;
    printf("Площадь трапеции равна: %lf\n", s);
    return 0;
}

