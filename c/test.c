#include <stdio.h>

int strlen1(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

int main()
{
    printf("%d\n", strlen1("hello"));
}