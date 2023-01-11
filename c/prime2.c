#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#define N 4000000

int main(){    
    bool arr[N+1];
    uint64_t sum = 0;

    for (uint64_t i = 0; i <= N; i++)
        arr[i] = true;
    
    for (uint64_t i = 2; (i*i) <= N; i++)
        if (arr[i])
            for (uint64_t j = (i*i); j <= N; j+= i)
                arr[j] = false;
    
    for (uint64_t i = 2; i <= N; i++)
        if (arr[i])
            sum += i;
    
    printf("%ld\n", sum);
}
