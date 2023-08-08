#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    /* Var */
    int limit = atoi(argv[1]), slim;
    bool prime[limit+1];
    int x = 0, y, i, j, n;

    /* Init */
    slim = (int)sqrt((long double)limit);

    for (i = 0; i <= limit; ++i)
        prime[i] = 0;

    prime[2] = 1;
    prime[3] = 1;

    for (i = 1; i <= slim; ++i) {
        x += 2 * i - 1;
        y = 0;
        for (j = 1; j <= slim; ++j) {
            y += 2 * j - 1;
        
            n = 4 * x + y;
            if ((n <= limit) && (n % 12 == 1 || n % 12 == 5))
                prime[n] = !prime[n];
        
            n -= x;         
            if ((n <= limit) && (n % 12 == 7))
                prime[n] = !prime[n];
        
            n -= 2 * y; 
            if ((n <= limit) && (i > j) && (n % 12 == 11))
                prime[n] = !prime[n];
        }
    }

    for (i = 5; i <= slim; ++i) {
        if (prime[i]) {
            n = i * i;
            for (j = n; j <= limit; j += n)
                prime[j] = false;
        }
    }

    printf("2, 3, 5");
    for (i = 6; i <= limit; ++i)
        if ((prime[i]) && (i % 3 != 0) && (i % 5 !=  0))
            printf(", %d", i);
    return 0;
}
