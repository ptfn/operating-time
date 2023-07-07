#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 60000
#define NUM_COLOR 4
#define FILL  10

typedef struct {
    int x;
    int y;
} Point;

void print_char(int x, int y)
{
    char c = rand() % 95 + 33;
    int color = rand() % NUM_COLOR + 1;
            
    attron(COLOR_PAIR(color));
    mvaddch(y, x, c);
    attroff(COLOR_PAIR(color));
}

void background(int mx, int my)
{
    for (int i = 0; i < mx; i++)
        for (int j = 0; j < my; j++)
            print_char(i, j);
}

int main()
{
    Point p = {0, 0}, m = {0, 0}, l = {0, 0};

    initscr();
    noecho();
    curs_set(FALSE);
    use_default_colors();
    start_color();

    // init_pair(1, COLOR_WHITE, COLOR_GREEN);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    // init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    // init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
    // init_pair(7, COLOR_WHITE, COLOR_CYAN);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);

    getmaxyx(stdscr, m.y, m.x);
    background(m.x, m.y);

    while(1) {
        getmaxyx(stdscr, l.y, l.x);

        if (m.x != l.x || m.y != l.y) {
            getmaxyx(stdscr, m.y, m.x);
            background(m.x, m.y);
        }

        for (int i = 0; i < m.x/FILL; i++) {
            print_char(p.x, p.y);
            p.x = rand() % m.x + 1;
            p.y = rand() % m.y + 1;
        }
        refresh();
        usleep(DELAY);
    }
    endwin();
}