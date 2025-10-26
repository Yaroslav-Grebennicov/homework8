#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() 
{
    setlocale(LC_ALL, "Rus");

    double a, sum = 0.0, term;
    int n, i;

    printf("вычисление суммы ряда: 1/a + 1/a^2 + 1/a^4 + ... + 1/a^2n\n\n");

    printf("введите значение a (a != 0): ");
    scanf("%lf", &a);

    if (a == 0) {
        printf("ошибка: a не может быть равно 0!\n");
        return 1;
    }

    printf("введите количество членов ряда n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("ошибка: n не может быть отрицательным !\n");
        return 1;
    }

    printf("\n");
    printf("+-----+--------------+--------------+\n");
    printf("|  i  |   степень'   |    сумма     |\n");
    printf("+-----+--------------+--------------+\n");

    for (i = 0; i <= n; i++) {
        int exponent = (i == 0) ? 1 : pow(2, i);
        term = 1.0 / pow(a, exponent);
        sum += term;

        printf("| %3d | 1/a^%-9d| %12.6f |\n", i, exponent, sum);
    }

    printf("+-----+--------------+--------------+\n");

    printf("\n итоговая сумма: %.8f\n", sum);

    return 0;
}