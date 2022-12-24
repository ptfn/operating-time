#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 5000 /* максимальное количество сортируемых строк */
#define MAXLENG 1000 /* максимальная длина входной строки */
#define ALLOCSIZE 10000 /* обьем имеющейся памяти */


char *lineptr[MAXLINE]; /* указатели на строки */
static char allocbuf[ALLOCSIZE]; /* буфер памяти для alloc */
static char *allocp = allocbuf; /* следущая свободная позиция */

char *alloc(int);
int getline(char *, int);
int numcmp(char *, char*);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort1(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));

/* сортировка строк входного потока */
int main(int argc, char *argv[])
{
    int nlines;         /* количество считанных строк */
    int numeric = 0;    /* 1, если числовая сортировка */

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
        qsort1((void **) lineptr, 0, nlines - 1,
            (int (*)(void*, void*)) (numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* qsort1: сортировка v[left] ... v[right] в порядке возрастания */
void qsort1(void *v[], int left, int right,
           int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)  /* ничего не делать, если в массиве */
        return;         /* меньше двух элеметов */
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort1(v, left, last-1, comp);
    qsort1(v, last+1, right, comp);
}

/* numcmp: сравнение строк s1 и s2 по числовым значениям */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* swap: обмен местами v[i] и v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* getline: считывает строку в s, возвращает её длину */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

/* readlines: считывание строк из входного потока */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLENG];

    nlines = 0;
    while ((len = getline(line, MAXLENG)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* удаление конца строки */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: вывод строк в выходной поток */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

char *alloc(int n)  /* возвращает указатель на n символов */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* есть место */
        allocp += n;
        return allocp - n; /* старый p */
    } else  /* недостаточно места в буфере */
        return 0;
}
