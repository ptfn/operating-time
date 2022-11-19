#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long power(int n, int m)
{
    int l = floor(log2(m)) + 1;
    long arr[l];
    long r = 1;
    int i;

    for (i = 0; i < l; i++)
        arr[i] = 1;

    for (i = 0; i < l; i ++) {
        if (m % 2 != 0)
            arr[i] = n;
        m = m / 2;
        n = n * n;
    }

    for (i = 0; i < l; i++)
        r *= arr[i];

    return r;
}

int main(int argc, char * argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("%ld\n", power(a, b));

    return 0;
}
