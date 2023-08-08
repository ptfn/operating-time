#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            printf("%02x ", argv[i][j]);
        }
    }
    putchar('\n');
    return 0;
}
