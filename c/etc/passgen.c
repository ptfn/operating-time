#include <sys/random.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    _Bool b, c, n, s;
    unsigned char lengthdict;
} dict_t;

static const char bigchars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char smallchars[] = "abcdefghijklmnopqrstuvwxyz";
static const char number[] = "0123456789";
static const char symbol[] = "!#$%&'()*+,-./:;<=>?@[\\]^_`{|}\"~ ";

char *gendictionary(dict_t args)
{
    char *dictionary = (char*)calloc(args.lengthdict, sizeof(char)); 

    if (args.b)
        strcat(dictionary, bigchars);
    if (args.c)
        strcat(dictionary, smallchars);
    if (args.n)
        strcat(dictionary, number);
    if (args.s)
        strcat(dictionary, symbol);
    return dictionary;
}

FILE *open(char *filename)
{
    FILE *file;
    if ((file = fopen(filename, "a+")) == NULL) {
        perror("Error occured while opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

char *getpassword(size_t length, char *dictionary, size_t lengthdict)
{
    char *password = (char*)calloc(length, sizeof(char));
    unsigned char buffer = 0;
    
    for (size_t i = 0; i < length; i++) {
        getrandom(&buffer, sizeof(char), 1);
        password[i] = dictionary[buffer%lengthdict];
    }
    return password;
}

int main(int argc, char **argv)
{
    dict_t args = {0, 0, 0, 0, 0};
    int ch, length = 8;
    char namepass[256];
    

    while ((ch = getopt(argc, argv, "bcnsl:f:")) != -1) {
        switch (ch) {
            case 'b':
                args.b = 1;
                args.lengthdict += 26;
                break;
            case 'c':
                args.c = 1;
                args.lengthdict += 26;
                break;
            case 'n':
                args.n = 1;
                args.lengthdict += 10;
                break;
            case 's':
                args.s = 1;
                args.lengthdict += 33;
                break;
            case 'l':
                length = atoi(optarg);
                break;
            case 'f':
                sprintf(namepass, "%s", optarg);
                break;
        }
    }

    FILE *filepass = open(namepass);
    char *dictionary = gendictionary(args);

    while (1) {
        char *password = getpassword(length, dictionary, strlen(dictionary));
        
        fprintf(filepass, "%s\n", password);
        
        for (int i = 0; i < length; i++)
            printf("\b");

        printf("%s", password);
    }

    fclose(filepass);
    return 0;
}
