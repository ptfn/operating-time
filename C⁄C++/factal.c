#include<stdio.h>

int factal(int n);

int main() {
    printf("Factal 10 = %d\n",factal(10));
    return 0;
}

int factal(int n){
    int res;
    if(n == 1) return n;
    res = factal(n-1)*n;
    return res;

}
