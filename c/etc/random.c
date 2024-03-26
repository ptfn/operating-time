#include<stdio.h>

unsigned int rand(){
    static unsigned int seed = 4541;
    seed = (65539 * seed + 0);
    return seed % 2147483648;
}

int main(){
    for(int n = 0; n <= 50; n++){
        printf("%d:\t%d\n",n+1,rand());
    }
}
