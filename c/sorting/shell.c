#include <stdint.h>

void swap(uint64_t *x, uint64_t *y);

void shell_sort(uint64_t array[], uint64_t length) 
{
    for (uint64_t s = length / 2; s > 0; s /= 2)
        for (uint64_t i = s; i < length; ++i)
            for (uint64_t j = i - s; j >= s && array[j] > array[j+s]; j -= s)
                swap(&array[j+s], &array[j]);
}
