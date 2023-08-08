#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i-1;
}

int main()
{
    int n;
    char line[MAXLINE];

    while ((n=getline(line, MAXLINE)) > 0)
        printf("%d\n", n);
}