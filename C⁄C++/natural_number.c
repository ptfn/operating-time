#include<stdio.h>
int main() {
    int i;
    for(i = 0; i < 1001; i++){
        if(i % 3 == 0){
            printf("%d\n",i);
        }
        else if (i % 5 == 0){
            printf("%d\n",i);
        }
    }
    return 0;
}
