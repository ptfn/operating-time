#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 10000000

int main()
{
    srand(time(0));
    double x, y, n = 0;
    uint64_t i = 0;

    while (i++ <= N) {
        double x = ((double)rand() / (double)(RAND_MAX));
        double y = ((double)rand() / (double)(RAND_MAX));
        double r = pow(x, 2) + pow(y, 2);

        if (r <= 1)
            n++;
    }
    printf("Num\t%d\nPi\t%.10lf\n", N, (n / i) * 4);
}
