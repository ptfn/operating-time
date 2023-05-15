#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define N 97 
#define MAX(a, b) (a > b ? a : b)

bool mutually_prime(uint16_t a, uint16_t b)
{
    for (uint16_t i = 2; i < MAX(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            return false;
        }
    }
    return true;
}

uint16_t euler_fi(uint16_t number)
{
    uint16_t n = 0;
    for (uint16_t i = 1; i < number; i++) {
        if (mutually_prime(number, i)) {
            n++;
        }
    } 
    return n;
}

uint32_t primal(uint16_t number)
{
    uint32_t i = 1, m = euler_fi(number);
    
    while (true) {
        for (uint32_t j = 1; j < m; j++) {
            uint32_t k = (long)(pow(i, j)) % number;
            if (k == 1) {
                i++; j = 1;
            }
        }
        break;
    }
    return i;
}

int main()
{
    printf("%d\t%d\n", N, primal(N));
    return 0;
}