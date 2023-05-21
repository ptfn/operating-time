#include <stdint.h>
#include <math.h>

/* Быстрый поиск делителей числа */
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

/* Быстрый подсчёт всех делителей числа */
uint32_t exc_div(uint16_t number)
{
    uint32_t result = 1;
    for (uint16_t i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            if (i != sqrt(number))
                result += i + (number / i); 
            else
                result += i;
    return result;
}

/* НОД */
uint32_t gcd(uint16_t a, uint16_t b)
{
    while (a != 0 && b != 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a + b;
}

/* НОК */
uint32_t lcm(uint16_t a, uint16_t b)
{
    return (a * b) / gcd(a, b);
}

/* Вычисление Степени */
uint64_t upow(uint64_t base, uint64_t exp)
{
    uint64_t result = 1;
    while (exp) {
        if (exp % 2)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}