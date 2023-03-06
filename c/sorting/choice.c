#include <stdint.h>

void swap(uint64_t *x, uint64_t *y);

uint64_t minimum(uint64_t array[], uint64_t length, uint64_t index)
{
    uint64_t min = index;
    for (uint64_t i = index; i < length; i++)
        if (array[i] < array[min])
            min = i;
    return min;
}

void choice_sort(uint64_t array[], uint64_t length)
{
    for (uint64_t i = 0; i < length; i++) {
        uint64_t index = minimum(array, length, i);
        swap(&array[i], &array[index]);
    }
}