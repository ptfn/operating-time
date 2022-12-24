char *strcat(char *s, char *t)
{
    char *pr = s + strlen(s);
    while(*pr != '\0')
        *pr++ = *t++;
    *pr = '\0';    
    return s;
}
