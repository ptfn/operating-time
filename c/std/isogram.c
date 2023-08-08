#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

bool IsIsogram (const char *string) {
    bool isogram[26] = {0};
    for (int i = 0; string[i] != '\0'; i++)
        if (isogram[tolower(string[i])-97]) return false;
        else isogram[tolower(string[i])-97] = 1;
    return true;
}

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        printf("%d\n", IsIsogram(argv[i]));
    }
    return 0;
}
