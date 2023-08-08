#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int find_odd (int length, const int array[length])
{
    struct { int n; int c; } result = {0, 0};
    for (int i = 0, c = 0; i < length; i++) {
        for (int j = 0; j < length; j++)
            if (array[i] == array[j])
                c++;
        if (c&1 && result.c < c) {
            result.n = array[i];
            result.c = c;
        }
        c = 0;
    }
    return result.n;
}

int find_odd2 (size_t length, const int array[length])
{
  int odd_int = 0;
  for (size_t i = 0; i < length; i++)
    odd_int ^= array[i];
  return odd_int;
}

int main(int argc, char **argv)
{
    int array[argc-1];

    for (int i = 1; i < argc; i++)
        array[i-1] = atoi(argv[i]);
    printf("%d\n", find_odd(argc-1, array));
    printf("%d\n", find_odd(11, ((const int[]) {1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5})));
    printf("%d\n", find_odd(35, ((const int[]) {39, 25, 60, -62, -59, -22, 65, 60, 70, -57, -59, 53, -2, 69, 1, 60, 99, 53, 99, 39, -57, 1, -94, 25, 60, -22, 55, 55, 70, 65, 5, 69, -62, -94, 5})));
    return 0;
}
