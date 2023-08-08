#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int fib(int n)
{
    if(n <= 2)
        return n;
    else 
        return(fib(n-1)+ fib(n-2));
}


float fib2(int n)
{
    float fi = (1 + sqrt(5)) / 2;
    float f = (pow(fi, n) - pow(-fi, -n)) / (2 * fi - 1);
    return floor(f);
}

int main(int argc, char * argv[])
{
    int n = atoi(argv[1]);
    // printf("Number Fib:%d\n", fib(n));
    printf("Number Fib:%.0f\n",fib2(n));
    return 0;
}
