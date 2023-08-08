#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* reverseWords(const char* text)
{
    int size = strlen(text);
    char* result = calloc(size, sizeof(char));
    strcpy(result, text);

    for (int i = 0, s = 0, e = 0; i < size; i++) {
        if ((result[i] == ' ' && i != size-1) || i == size-1) {
            e = (i == size-1 && result[i] != ' ') ? i+1 : i;
            for (int j = 0; j < (e-s)/2; j++) {
                char temp = result[j+s];
                result[j+s] = result[e-j-1];
                result[e-j-1] = temp;
            }
            s = e + 1;
        } 
    } 
    return result;
}

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++) {
        printf("%s", reverseWords(argv[i]));
    }
    return 0;
}
