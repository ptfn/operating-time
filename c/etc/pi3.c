#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

uint16_t F(uint16_t number, uint16_t i) { return (int)(number % (int)pow(10, i) / pow(10, i-1));}

int main(int argc, char **argv)
{
    uint64_t n = strtoull(argv[1], NULL, 10), l = 10 * n / 3 ;
    uint16_t *init = (uint16_t*)calloc(l, sizeof(uint16_t)), *num = (uint16_t*)calloc(l, sizeof(uint16_t));
    uint8_t *result = (uint8_t*)calloc(n, sizeof(uint8_t));

    for (uint64_t i = 0; i < l; i++) {
        num[i] = i > 0 ? (2*(i-1))+3 : 0;
        init[i] = 2;
    }

    for (uint64_t j = 0; j < n; j++) {
        uint16_t sum[l], ren[l]; 
        sum[l-1] = 10 * init[l-1];
        
        for (uint64_t i = l-1; i > 0; i--) {
            init[i-1] *= 10;
            ren[i-1] = floor(sum[i] / (num[i] / 1.0)) * i;
            sum[i-1] = ren[i-1] + init[i-1];
            init[i] = sum[i] % num[i];
        }
        result[j] = F(sum[0], 2); // sum[0] % 10
        init[0] = F(sum[0], 1);   // sum[0] / 10
    }
    for (uint64_t i = 0; i < n; i++) printf("%d ", result[i]);
    return 0;
}
