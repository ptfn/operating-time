#include <stdlib.h>
#include <stdio.h>

char *range_extraction(const int *args, size_t n)
{
    char *buffer = calloc(n*4, sizeof(char));
    int length = 0;
    for (size_t i = 0, j = 0; i < n; i++, j = 0) {
        length += sprintf(buffer+length, "%d", args[i]);
        for (; i+j < n-1 && args[i+j] - args[i+j+1] == -1; j++);
        if (j > 1) length += sprintf(buffer+length, "-%d", args[i += j]); 
        if (i != n-1) length += sprintf(buffer+length, ",");
    }
    return buffer;
}

int main(int argc, char const **argv)
{
    printf("%s\n", range_extraction((const int[]){ -6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20 }, 20ul));
    printf("%s\n", range_extraction((const int[]){ -3,-2,-1,2,10,15,16,18,19,20 }, 10ul));
    printf("%s\n", range_extraction((const int[]){ -5,-4,-3,-2,-1,0,1,2,3,4,5 }, 11ul));
    printf("%s\n", range_extraction((const int[]){ -5,-4,-2,-1,1,2,4,5 }, 8ul));
    printf("%s\n", range_extraction((const int[]){ 9 }, 1ul));
    return 0;
}
