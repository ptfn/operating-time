#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 100000
#define FILL  1

typedef struct {
    int x;
    int y;
} Point;

int main()
{
    Point p1;
    p1.x = 0; p1.y = 0;
    int max_y = 0, max_x = 0;

    initscr();
    noecho();
    curs_set(FALSE);

    getmaxyx(stdscr, max_y, max_x);

    while(1) {
        clear();
        for (int i = 0; i < max_x/FILL; i++) {
            mvprintw(p1.y, p1.x, "o");
            p1.x = rand() % max_x + 1;
            p1.y = rand() % max_y + 1;
        }
        refresh();
        usleep(DELAY);
    }

    endwin();
}