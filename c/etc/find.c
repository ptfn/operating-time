#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LEN_DIRECTORY 1024
#define BLUE_COLOR        34
#define RESET_COLOR       0

static size_t count_find = 0;

char *paint_text(char *string, int color)
{
    char *result = (char*)malloc(MAX_LEN_DIRECTORY*sizeof(char));
    sprintf(result, "\033[%dm%s\033[%dm", color, string, RESET_COLOR);
    return result;
}

char *lower(char *string)
{
    char *result = (char*)malloc(strlen(string)*sizeof(char));
    for (size_t i  = 0; i < strlen(string); i++)
        result[i] = tolower(string[i]);
    return result;
}

int coincidence(char *src, char *dest)
{
    size_t srcs = strlen(src);
    size_t dests = strlen(dest);

    char *srcl = lower(src);
    char *destl = lower(dest);

    if (srcs > dests) return 0;

    for (size_t i = 0, j = 0; i < srcs;) {
        if (srcl[i] != destl[j+i]) {
            if (++j > dests-srcs) return 0;
            i = 0;
        } else
            i++;
    }
    return 1;
}

void find(char *hidden, char *directory)
{
    struct dirent *ent;
    DIR *listdir;

    listdir = opendir(directory);

    if (listdir != NULL) {
        while ((ent=readdir(listdir)) != 0) {
            if (coincidence(hidden, ent->d_name)) {
                printf(strcmp(directory, ".") ? "%s/" : " ", directory);
                puts(paint_text(ent->d_name, BLUE_COLOR));
                count_find++;
            }

            if (strcmp(ent->d_name, ".") && strcmp(ent->d_name, "..")) {
                char *new_directory = (char*)malloc(MAX_LEN_DIRECTORY*sizeof(char));
                memset(new_directory, 0, strlen(new_directory));

                if (strcmp(directory, ".")) {
                    strcat(new_directory, directory);
                    strcat(new_directory, directory[strlen(directory)-1] == '/' ? "" : "/");
                } else {
                    char *now_directory = (char*)malloc(MAX_LEN_DIRECTORY*sizeof(char));
                    getcwd(now_directory, MAX_LEN_DIRECTORY*sizeof(char));

                    strcat(new_directory, now_directory);
                    strcat(new_directory, "/");
                    free(now_directory);
                }

                strcat(new_directory, ent->d_name);
                find(hidden, new_directory);
            }
        }
        closedir(listdir);
    } 
}

int main(int argc, char **argv)
{
    int c;
    char *hidden = (char*)malloc(MAX_LEN_DIRECTORY*sizeof(char));
    char *path = (char*)malloc(MAX_LEN_DIRECTORY*sizeof(char));

    while ((c = getopt(argc, argv, "h:p:")) != -1) {
        switch (c) {
            case 'h': case 'H':
                hidden = optarg;
                break;
            case 'p': case 'P':
                path = optarg;
                break;
        }
    }

    if (strcmp(hidden, "") && strcmp(path, "")) {
        find(hidden, path);
        printf("Find\t%ld\n", count_find);
    } else
        perror("No args");

    return 0;
}

