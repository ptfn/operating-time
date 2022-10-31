#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    float sum = 0;

    for(int i = 1; i < argc; i++)
        sum += atof(argv[i]);


    printf("%.1f\n", sum);
    return 0;
}