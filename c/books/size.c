#include <stdio.h>

int main()
{
    printf("CHAR\t%ld\n", sizeof(char));
    printf("SHORT\t%ld\nINT\t%ld\nLONG\t%ld\n",sizeof(short), sizeof(int), sizeof(long));
    printf("FLOAT\t%ld\nDOUBLE\t%ld\n",sizeof(float), sizeof(double));
    return 0;
}