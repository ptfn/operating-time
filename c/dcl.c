#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;              /* тип последней лексемы */
char token[MAXTOKEN];       /* последняя введенная лексема */
char name[MAXTOKEN];        /* имя идентификатора */
char datatype[MAXTOKEN];    /* тип данных = char, int и т.п. */
char out[1000];             /* строка результата */
char buf[BUFSIZE];
int bufp = 0;

/* преобразование объявлений в словесную форму */
int main()
{
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
}

/* dcl: синтаксический анализ объявления */
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*'; ) /* подсчёт знаков * */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: синтаксический анализ прямого объявления */
void dirdcl(void)
{
    int type;

    if(tokentype == '(') {      /* (обвл) */
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME)       /* Имя переменной */
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, "of");
        }
}

int gettoken(void)
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}