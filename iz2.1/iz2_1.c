#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>


double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU");
    double a, b;            
    int k;                  
    double epsilon;         
    double h, x, sum, term, exact, error;
    int n;

    printf("Введите начало интервала a: ");
    scanf("%lf", &a);
    printf("Введите конец интервала b: ");
    scanf("%lf", &b);
    printf("Введите количество точек k: ");
    scanf("%d", &k);
    printf("Введите точность epsilon: ");
    scanf("%lf", &epsilon);
   
    h = (b - a) / (k - 1);

    printf("\nx\tРяд\t\tТочное значение\tОшибка\n");

    for (int i = 0; i < k; i++) {
        x = a + i * h; 
        sum = 0.0;
        n = 1;

        do {
            term = pow(sin(n * x), 1.0) / factorial(n);
            sum += term;
            n++;
        } while (fabs(term) > epsilon);

        exact = exp(sin(x)) * sin(cos(x));
        error = fabs(sum - exact);

        printf("%lf\t%lf\t%lf\t%lf\n", x, sum, exact, error);
    }

    return 0;
}
