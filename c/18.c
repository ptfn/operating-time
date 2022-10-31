#include <locale.h>
#include <stdio.h>
#include <math.h>

int fac(int n)
{
    int res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

void main()
{
    setlocale(LC_ALL, "rus"); /*подключаем русский язык*/
    
    double e = 2.71828, L, P;
    int x;
    
    printf ("Введите x \n");
    scanf ("%d", &x);
    
    L=((1 + 2)*pow(x,2))*e * pow(x,2);

    for(int i = 1; i <= 5; i++) {
        P+=(((2*i + 1) * pow(x,2*i)) / fac(i));
    }


    printf("L=%.1lf P=%.1lf\n", L, P);
}