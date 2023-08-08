#include <stdio.h>

int main(void)
{
    unsigned char c = 128;
    char *s = "Hello!";
    long l = 1234;
    double d = 3.1415;

    printf("%02x %.3s %.10lf %+ld %a\n", c, s, d, l, d);

    return 0;
}
