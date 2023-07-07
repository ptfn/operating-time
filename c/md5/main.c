#include <stdio.h>
#include "md5.h"

int main(int argc, char **argv)
{
    char *message = calloc(128, sizeof(char));
    char hash[32];
    
    for (uint16_t i = 1; i < argc; i++) {
        strcpy(message, argv[i]);
        size_t lenght = strlen(message); 
        md5(message, lenght, hash);
        puts(hash);
    }
    // size_t len = strlen(message);
 
    // md5(message, len, hash);
    // puts(hash);
    
    return 0; 
}