#include <stdio.h>
#include <string.h>

#define MAXLINE 5000 /* максимальное количество сортируемых строк */

char *lineptr[MAXLINE]; /* указатели на строки */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

/* сортировка строк входного потока */
int main()
{
    int nlines; /* количество введенных строк */

    if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}