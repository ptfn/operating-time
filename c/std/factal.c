#include <stdio.h>

int fac(int n){
    int res;
    if(n == 1) return n;
    res = fac(n-1)*n;
    return res;
}

int main() {
    int n = 30;
    printf("Factal %d = %d\n", n, fac(n));
    return 0;
}