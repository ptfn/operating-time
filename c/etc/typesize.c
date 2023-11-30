#include <stdio.h>

int main(void)
{
    printf("%s %zd\n", "char", sizeof(char));
    printf("%s %zd\n", "short", sizeof(short));
    printf("%s %zd\n", "int", sizeof(int));
    printf("%s %zd\n", "long", sizeof(long));
    printf("%s %zd\n", "long long", sizeof(long long));
    printf("%s %zd\n", "float", sizeof(float));
    printf("%s %zd\n", "double", sizeof(double));
    printf("%s %zd\n", "long double", sizeof(long double));
    return 0;
}
