#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *s, int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0)
        if (strstr(line, argv[1]) != NULL) {
            printf("%s", line);
            found++;
        }
    printf("%d\n", found);
    return 0;
}