#include <stdlib.h>
#include <string.h>
#include <math.h>
#define F(n, i) (int)(n / pow(10, i)) % 10

#include <stdio.h>

void incrementString(const char *str)
{
    char *number = calloc(strlen(str), sizeof(char)); 
    char *result = calloc(strlen(str)+1, sizeof(char));
    int spl = strlen(str);
    strcpy(result, str);

    for (int i = strlen(str)-1; str[i] >= '0' && str[i] <= '9'; i--)
        spl = i;
    for (int i = spl, j = 0; str[i] != '\0'; i++)
        number[j++] = str[i];

    int length = (int)log10(atoi(number)+1)+1, num = atoi(number)+1;
    int size = length > strlen(number) ? strlen(str) : strlen(str)-1; 

    for (int i = size; i > size-length; i--)
       result[i] = F(num, size-i) + '0';

    return result;
}

int main(int argc, char **argv)
{
    incrementString("foobar000");
    incrementString("foobar999");
    incrementString("foo");
    incrementString("1");
    incrementString("");
    incrementString("fo99obar99");
    return 0;
}
