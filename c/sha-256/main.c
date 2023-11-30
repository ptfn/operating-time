#include <string.h>
#include <stdio.h>
#include "sha256.h"

int main(int argc, char *argv[])
{
    // char *message = (char*)calloc(256, sizeof(char));
    char *test_hash = "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824";
    char *message = "hello";
    char hash[64];

    sha256(message, strlen(message), hash);
    
    if (!(strcmp(test_hash, hash)))
        puts("Correct!");
    else
        puts("False!");

    // for (uint16_t i = 1; i < argc; i++) {
    //     strcpy(message, argv[i]);
    //     size_t lenght = strlen(message); 
    //     sha256(message, lenght, hash);
    //     puts(hash);
    // }
    return 0; 
}