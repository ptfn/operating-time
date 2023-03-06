#include <stdint.h>

void swap(uint64_t *x, uint64_t *y);

void bubble_sort(uint64_t array[], uint64_t length)
{
    for (uint64_t i = 0; i < length-1; i++)
        for (uint64_t j = 0; j < length-1; j++)
            if (array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
}