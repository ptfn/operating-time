#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LENGTH 1000000

void bubble_sort(uint64_t array[], uint64_t length);
void choice_sort(uint64_t array[], uint64_t length);
void insert_sort(uint64_t array[], uint64_t length);
void shell_sort(uint64_t array[], uint64_t lenght);

void generate_array(uint64_t array[], uint64_t length)
{
    srand(time(0));
    for (uint64_t i = 0; i < length; i++)
        array[i] = rand() % length + 1;
}

void print_array(uint64_t array[], uint64_t length)
{
    for (uint64_t i = 0; i < length; i++)
        if (i % 20 != 0)
            printf("%ld\t", array[i]);
        else
            putchar('\n');
    putchar('\n');
}

int main()
{
    uint64_t array[LENGTH];
    generate_array(array, LENGTH);
    // print_array(array, LENGTH);

    // choice_sort(array, LENGTH);
    // bubble_sort(array, LENGTH);
    // insert_sort(array, LENGTH);
    shell_sort(array, LENGTH);
    
    // print_array(array, LENGTH);
}