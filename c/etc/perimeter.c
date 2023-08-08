#include <stdio.h>

typedef unsigned long long ull;
ull next(ull *a, ull *b){ull temp=*a+*b; *a=*b; *b=temp; return *b;}

ull perimeter(int n) {
    ull res = 0, a = 0, b = 1, i = 1;     
    while (i++ <= n) res += next(&a, &b);
    return 4*(res+1);
}

int main()
{
    printf("%lld\n", perimeter(1));
    printf("%lld\n", perimeter(5));
    printf("%lld\n", perimeter(7));
    printf("%lld\n", perimeter(20));
    printf("%lld\n", perimeter(30));
    
    return 0;
}
