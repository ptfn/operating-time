#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {char *text; int number;} Int;

Int numbers[28] = { {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7},
                    {"eight", 8}, {"nine", 9}, {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
                    {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
                    {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90} };

long parse_int (const char* number) {
    char *text = (char*)malloc(strlen(number) * sizeof(char));
    strcpy(text, number);
    char *pch = strtok(text, " -");
    long temp = 0, th = 0;

    while (pch != NULL) {
        if (strcmp(pch, "hundred") == 0)
            temp *= 100;
        else if (strcmp(pch, "thousand") == 0) {
            th = temp * 1000; temp = 0;
        } else if (strcmp(pch, "million") == 0)
            temp *= 1e6;
        else
            for (int i = 0; i < 28; i++)
                if (strcmp(pch, numbers[i].text) == 0)
                    temp += numbers[i].number;
        pch = strtok(NULL, " -");     
    }
    free(text);
    return th+temp;
}

int main()
{
    printf("%ld\n", parse_int("one"));
    printf("%ld\n", parse_int("twenty"));
    printf("%ld\n", parse_int("two hundred and forty-six"));
    printf("%ld\n", parse_int("four thousand five hundred fifty three"));
    printf("%ld\n", parse_int("five million"));
    printf("%ld\n", parse_int("one thousand five hundred"));
    printf("%ld\n", parse_int("seven hundred eighty-three thousand nine hundred and nineteen"));

    return 0;
}
