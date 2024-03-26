#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_CHAR_FILE 50

/* Protitype */
FILE  *open(char *filename, char *mode);
int   get(FILE *file);
char  *temp(char *path);
char  *light(char *path_now, char *path_max);
char  *timer(void);


