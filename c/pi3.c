#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define N   1001
#define LEN 10*N/3

uint16_t F(uint16_t number, uint16_t i) 
{
    return (int)(number % (int)pow(10, i) / pow(10, i-1));
}

int main()
{
    /* Init Variables */
    uint8_t result[N];
    uint16_t init[LEN];
    uint16_t num[LEN];

    /* Init Array */
    for (uint64_t i = 0; i < LEN; i++) {
        num[i] = i > 0 ? (2*(i-1))+3 : 0;
        init[i] = 2;
    }

    /* Main Calculations */
    for (uint64_t j = 0; j < N; j++) {
        uint16_t sum[LEN];
        uint16_t ren[LEN];
         
        sum[LEN-1] = 10 * init[LEN-1];
        
        for (uint64_t i = LEN-1; i > 0; i--) {
            init[i-1] *= 10;
            ren[i-1] = floor(sum[i] / (num[i] / 1.0)) * i;
            sum[i-1] = ren[i-1] + init[i-1];
            init[i] = sum[i] % num[i];
        }
        /* Debug INIT */
        /* Her Problem - 492 */
        result[j] = F(sum[0], 2); // sum[0] % 10
        init[0] = F(sum[0], 1);   // sum[0] / 10
    }

    /* Out In Console */
    for (uint64_t i = 0; i < N; i++) {
        if (i % 10 == 0)
            printf("%d  ", result[i]);
        else
            printf("%d", result[i]);

        if (i % 120 == 0)
            putchar('\n');        
    }
    putchar('\n');

    return 0;
}
