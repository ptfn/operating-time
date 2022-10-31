#include <stdio.h>

#define IN  1 /* внутри слова */
#define OUT 0 /* снаружи слова */

/* подсчёт строк, слов и символов во входном потоке */
int main()
{
    int c, n1, nw, nc, state;

    state = OUT;
    n1 = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') /* подсчёт строк */
            ++n1;
        if(c == ' ' || c == '\n' || c == '\t') /* подсчёт слов */
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", n1, nw, nc);
}