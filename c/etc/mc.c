#include <ncurses.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_DIR 1024
#define BEGIN_LINE   2

/*
 * Move dir
 * See file 
 * More list scroling
 */

static short list(DIR *directory, struct dirent *entry, short cursor)
{
    short i = 0;
    
    while ((entry=readdir(directory)) != 0) {
        if (strcmp(entry->d_name, ".")) {
            if (i == cursor) 
                wattron(stdscr, A_STANDOUT);
            mvprintw(BEGIN_LINE + i++, 0, "%s", entry->d_name);
            wattroff(stdscr, A_STANDOUT);
        }
    }
    return i;
}

int main(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    curs_set(false);

    char *dir = (char *)malloc(MAX_NAME_DIR);
    short ch, cursor = 0, maxline;
    struct dirent *entry = malloc(sizeof(struct dirent));
    DIR *listdir = NULL;
    
    while(1) {
        clear();
        
        if (getcwd(dir, MAX_NAME_DIR) != NULL) {
            listdir = opendir(dir);
            mvprintw(0, 0, "PATH: %s", dir);
        }

        maxline = list(listdir, entry, cursor)-1;
        ch = getch();

        switch (ch) {
            case KEY_UP:
                cursor--;
                cursor = (cursor < 0) ? maxline : cursor;
                break;
            case KEY_DOWN:
                cursor++;
                cursor = (cursor > maxline) ? 0 : cursor;
                break;
            case 'q': case 'Q':
                endwin();
                exit(0);
                break;
        }

        closedir(listdir); 
    }

    return 0;

}
