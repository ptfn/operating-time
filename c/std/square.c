#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

bool is_square(int n)
{
    return sqrt(n) == (int)(sqrt(n));
}

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        printf("%d\n", is_square(atoi(argv[i])));
    }
    return 0;
}
