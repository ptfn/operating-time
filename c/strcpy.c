char* strcpy2(char *s, const char *t)
{
    char *tmp = s;
    while (*s++ = *t++)
        ;
    return tmp;
}

char* strncpy2(char *s, const char *t, int l)
{
    char *tmp = s;
    int i = 0;
    while (i++ < l)
        *s++ = *t++;
    return tmp;
}
