#include <stdint.h>
#include <math.h>

/* Быстрый поиск делителей у числа */
uint32_t divider(uint64_t number)
{
    uint32_t result = 0;
    for (uint32_t i = 1; i <= sqrt(number); i++)
        if (number % i == 0)
            result++;
    
    if (sqrt(number) == (int)sqrt(number)) 
        return 2 * result - 1;
    return 2 * result; 
}