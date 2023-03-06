#include <stdint.h>

void swap(uint64_t *x, uint64_t *y)
{
    uint64_t temp = *x;
    *x = *y;
    *y = temp;
}