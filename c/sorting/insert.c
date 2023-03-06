#include <stdint.h>

void swap(uint64_t *x, uint64_t *y);

void insert_sort(uint64_t array[], uint64_t length)
{
    for (uint64_t i = 1; i < length; i++) {
        for (uint64_t j = i; array[j-1] > array[j] && j > 0; j--)
            swap(&array[j-1], &array[j]);
    }
}