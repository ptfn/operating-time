#include<stdio.h>

int main()
{
    double num, den, oper, pi;
    unsigned int n;

    num = 4.0f;
    den = 1.0f;
    oper = 1.0f;
    pi = 0.0f;

    for (n = 0;n <= 999999; n ++){
        pi += oper * (num / den);
        den += 2.0f;
        oper *= -1.0f;
    }
    printf("Pi: %.10f\n",pi);
}
