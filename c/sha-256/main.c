#include <stdio.h>
#include "sha256.h"

int main(int argc, char **argv)
{
    char *message = calloc(256, sizeof(char));
    char hash[32];
    
    for (uint16_t i = 1; i < argc; i++) {
        strcpy(message, argv[i]);
        size_t lenght = strlen(message); 
        sha256(message, lenght, hash);
        puts(hash);
    }
    return 0; 
}