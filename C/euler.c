#include <stdio.h>
#include <math.h>

int factal(int n){
    int res;
    if(n == 1) return n;
    res = factal(n-1)*n;
    return res;
}

int main(){
    double e;
    for(int i = 0; i < 10; i++){
        e += 1 / factal(i);
    }
    printf("E: %.10f\n", e);
    return 0;
}