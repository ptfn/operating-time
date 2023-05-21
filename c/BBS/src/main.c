#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define F(n) ((int)(floor(log10(n)) + 1))

typedef struct M
{
    uint64_t p;
    uint64_t q;
}M;

uint64_t gcd(uint64_t a, uint64_t b)
{
    while (a != 0 && b != 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a + b;
}

uint64_t lcm(uint64_t a, uint64_t b)
{
    return (a * b) / gcd(a, b);
}

void prime_number(uint64_t limit, uint64_t prime[], uint64_t length)
{
    bool *arr;
    arr = (bool*)calloc(limit+1, sizeof(bool));
    uint64_t j = 0, k = 0, i;

    for (uint64_t i = 0; i <= limit; i++)
        arr[i] = true;

    for (uint64_t i = 2; (i*i) <= limit; i++)
        if (arr[i])
            for (uint64_t j = (i*i); j <= limit; j+= i)
                arr[j] = false;

    i = 1;

    while (i++ <= limit) {
        if (arr[i])
            if (k < length) {
                prime[k] = i;
                k++;
            } else
                break;
    }
}

void comparable_number(uint64_t prime[], uint64_t length_prime, 
                       M comparable[], uint64_t length_comparable)
{
    for (uint64_t i = length_prime, m = 0; i > 0; i--) {
        for (uint64_t j = 0; j < i; j++) {
            if (prime[i] % 4 == 3 && prime[j] % 4 == 3 
                && gcd(prime[i], prime[j]) == 1
                && F(prime[i]) == F(prime[j])) {
                comparable[m].p = prime[i];
                comparable[m].q = prime[j];
                m++;
            }
        }
        if (m >= length_comparable) {
            break;
        }
    }
}

/* Generate Sequence Random Numbers */
void generate_random(M comparable, uint64_t x0, uint64_t limit)
{
    printf("Parameter: p - %ld q - %ld x0 - %ld\n\n", comparable.p, comparable.q, x0);
    uint64_t M = comparable.p * comparable.q;
    uint64_t lambda_M = lcm(comparable.p-1, comparable.q-1);
    uint64_t x1 = (uint64_t)pow(x0,2 % lambda_M) % M;

    for (uint64_t i = 0; i < limit; i++) {
        x1 = (uint64_t)pow(x1, 2) % M;
        
        printf("%ld\t", x1);
        if ((i+1) % 20 == 0)
            puts("\n");
    }
}

int main()
{
    /* Parameter Initialization */
    uint64_t limit = 1e7, length_prime = 1e2, length_comparable = 1e3;
    uint64_t prime[length_prime];
    M comparable[length_comparable];

    /* Generate Number */
    prime_number(limit, prime, length_prime);
    comparable_number(prime, length_prime, comparable, length_comparable);
    generate_random(comparable[50], prime[13], 1e5);

    /* Print Comparable Numbers (GCD = 1) */
    // for (uint64_t i = 0; i < length_comparable; i++) {
    //     if (comparable[i].p <= 0 || comparable[i].q <= 0)
    //         break;
    //     printf("%ld. %ld %ld\n", i, comparable[i].p, comparable[i].q);
    // }
    return 0;
}
