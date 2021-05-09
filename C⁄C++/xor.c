#include <stdio.h>
#include <string.h>

int encrypt(int text, int key){
    int encrypt;
    return encrypt = text ^ key;
}

int decrypt(int text, int key){
    int decrypt;
    return decrypt = text ^ key;
}

int main(void){
    unsigned long text, key;
    char menu[1];

    printf("Text:");
    scanf("%ld", &text);

    printf("Key:");
    scanf("%ld", &key);

    printf("Menu:");
    scanf("%s", &menu);

    if(strcmp(menu, "e") == 0)
        printf("Encrypt text: %d\n", encrypt(text, key));
    else if(strcmp(menu, "d") == 0)
        printf("Decrypt text: %d\n", decrypt(text, key));
    else
        printf("Error!\n");

    return 0;
}