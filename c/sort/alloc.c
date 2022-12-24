#define ALLOCSIZE 10000 /* обьем имеющейся памяти */

static char allocbuf[ALLOCSIZE]; /* буфер памяти для alloc */
static char *allocp = allocbuf; /* следущая свободная позиция */

char *alloc(int n)  /* возвращает указатель на n символов */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* есть место */
        allocp += n;
        return allocp - n; /* старый p */
    } else  /* недостаточно места в буфере */
        return 0;
}