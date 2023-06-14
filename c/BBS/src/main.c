#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define SIZE(n) ((int)(floor(log10(n)) + 1))
#define PARITY(n) (n&1)

typedef struct M
{
    uint16_t p;
    uint16_t q;
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

/* Generate Prime Numbers */
void prime_number(uint64_t limit, uint64_t prime[], uint64_t length)
{
    bool* arr;
    arr = (bool*)calloc(limit + 1, sizeof(bool));

    uint64_t j = 0, k = 0, i;

    for (i = 0; i <= limit; i++)
        arr[i] = true;

    for (i = 2; (i * i) <= limit; i++)
        if (arr[i])
            for (j = (i * i); j <= limit; j += i)
                arr[j] = false;

    i = 32000;

    while (i++ <= limit) {
        if (arr[i])
            if (k < length) {
                prime[k] = i;
                k++;
            }
            else
                break;
    }
    free(arr);
}

/* Generate Comparable Numbers */
void comparable_number(uint64_t prime[], uint64_t length_prime,
                       M comparable[], uint64_t length_comparable)
{
    for (uint64_t i = length_prime, m = 0; i > 0; i--) {
        for (uint64_t j = 0; j < i; j++) {
            if (prime[i] % 4 == 3 && prime[j] % 4 == 3
                && gcd(prime[i], prime[j]) == 1
                && SIZE(prime[i]) == SIZE(prime[j])) {
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

/* Generate Seed */
uint64_t generate_xzero(uint64_t M)
{
    uint64_t x0;

    while (true) {
        x0 = time(0) % M;

        if (x0 == 0 || x0 == 1)
            continue;
        
        if (gcd(x0, M) == 1)
            return x0;
    }
}

/* Generate Sequence Random Numbers */
void generate_random(M comparable, uint64_t limit)
{
    uint64_t M = comparable.p * comparable.q;
    uint64_t x0 = generate_xzero(M);
    uint64_t lambda_M = lcm(comparable.p-1, comparable.q-1);
    uint64_t x1 = (uint64_t)pow(x0,2 % lambda_M) % M;

    printf("Parameter: p - %d q - %d x0 - %ld\n\n", comparable.p, comparable.q, x0);

    for (uint64_t i = 0; i < limit; i++) {
        x1 = (x1 * x1) % M;
        printf("%ld", PARITY(x1));
    }
    putchar('\n');
}

int main()
{
    /* Parameter Initialization */
    // Problem size prime and comparable
    uint64_t limit = 1e7, length_prime = 1e3, length_comparable = 1e5;
    uint64_t prime[length_prime];
    M comparable[length_comparable];
    
    /* Generate Number */
    prime_number(limit, prime, length_prime);
    comparable_number(prime, length_prime, comparable, length_comparable);
    generate_random(comparable[time(0) % length_comparable], 64);

    return 0;
}
