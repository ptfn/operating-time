#include "status.h"
#include <stdlib.h>
#include <time.h>

/* Open File */
FILE *open(char *filename, char *mode)
{
    FILE *file;
    if ((file = fopen(filename, mode)) == NULL) {
        perror("Error occured while opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

/* Get Value File */
int get(FILE *file)
{
    char *file_value = (char*)calloc(NUM_CHAR_FILE, sizeof(char));
    fgets(file_value, NUM_CHAR_FILE, file);
    return atoi(file_value);
}

/* Get Temp File To String */
char *temp(char *path)
{
    FILE *file = open(path, "r");
    char *res = (char*)calloc(NUM_CHAR_FILE, sizeof(char));
    sprintf(res, "%d", get(file)/1000);
    return res;
}

/* Get Light File To String */
char *light(char *path_now, char *path_max)
{
    FILE *file_now = open(path_now, "r");
    FILE *file_max = open(path_max, "r");
    char *res = (char*)calloc(NUM_CHAR_FILE, sizeof(char));
    sprintf(res, "%d",(int)(((float)get(file_now) / (float)get(file_max)) * 100));
    return res;
}

/* Get Time */
char *timer(void)
{
    time_t now = time(NULL);
    char *res = (char*)calloc(NUM_CHAR_FILE, sizeof(char));
    strftime(res, NUM_CHAR_FILE, "%c", localtime(&now));
    return res;
}
