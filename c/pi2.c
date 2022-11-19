#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define R 102400
#define N 1000000000
int main()
{
    srand(time(0));
    double num = 0;
    unsigned long long int i = 0, x, y;

    while (i++ <= N) {
        x = 1 + rand() % R;
        y = 1 + rand() % R;

        if (pow(x, 2) + pow(y, 2) <= pow(R, 2))
            num++;
    }
    printf("Num\t%d\nPi\t%.10lf\n", N, (num / i) * 4);
}