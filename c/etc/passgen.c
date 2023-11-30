#include <sys/random.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    _Bool b, c, n, s, g;
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

void init(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    curs_set(false);
}

int main(int argc, char *argv[])
{
    struct timespec delay = {0, 0}, tr;
    int ch, length = 8, x = 0, y = 0;
    char namepass[256];
    clock_t timefunc;
    _Bool bdelay = 0;
    double timegen;
    
    dict_t args = {0, 0, 0, 0, 0, 0};

    while ((ch = getopt(argc, argv, "gbcnsl:f:t:")) != -1) {
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
            case 'g':
                args.g = 1;
                break;
            case 't':
                delay.tv_sec = atoi(optarg);
                bdelay = 1;
                break;
        }
    }

    if (args.g) {
        init();
        getmaxyx(stdscr, y, x);
    }

    WINDOW *win = newwin(7, 34, y/2 - (7/2), x/2 - (34/2));

    FILE *filepass = open(namepass);
    char *dictionary = gendictionary(args);

    while (1) {
        timefunc = clock();
        char *password = getpassword(length, dictionary, strlen(dictionary));
        timefunc = clock() - timefunc;
        timegen = ((double)timefunc)/CLOCKS_PER_SEC;
       
        if (args.g) {
            box(win, 0, 0);
            mvwprintw(win, 1, 34/2-4, "PassGen");
            mvwprintw(win, 2, 1, "Password: %s", password);
            mvwprintw(win, 3, 1, "Speed:    %.0lf p/s", 60.0 / timegen);
            wrefresh(win);
            werase(win);
        }

        fprintf(filepass, "%s\n", password);
    
        if (bdelay)
            nanosleep(&delay, &tr);
    }

    fclose(filepass);

    if (args.g) {
        delwin(win);
        endwin();
    }
    return 0;
}
