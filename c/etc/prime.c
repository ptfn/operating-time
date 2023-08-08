#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#define N 5000000

int main(){    
    bool arr[N+1];
    uint64_t sum = 2;

    for (uint64_t i = 1; i <= N; i++)
        arr[i] = true;

    for (uint64_t i = 1; 2 * i * (i + 1) < N; i++)
        for (uint64_t j = i; j < (N-1) / (2 * i + 1); j++)
            arr[2* i * j + i + j] = false;

    for (uint64_t i = 1; i <= N; i++)
        if (arr[i] && (2 * i + 1) <= N)
                sum += 2*i+1;
    
    printf("%ld\n", sum);
}
