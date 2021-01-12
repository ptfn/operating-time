#include <stdio.h>
#include <math.h>

int fib (int n){
    return (pow(((1+sqrt(5)) / (2)),n) - pow(((1-sqrt(5)) / (2)),n)) / sqrt(5);
}

int main(){
    printf("Number Fib:%d\n",fib(40));
    return 0;
}
