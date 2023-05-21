#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#define MAX(a, b) (a > b ? a : b)
#define TIMING 1000
#define LIMIT  15

typedef struct Point{
    int x;
    int y;
} Point;

typedef struct Player{
    Point p;
    uint16_t win;
} Player;


Point m = {0, 0}, c = {0, 0};
Player p1 = {0, 1, 0}, p2 = {0, 1, 0};

void key_event(void)
{
    struct timespec length = {0, 0};
    short i, c;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);

    switch(c = wgetch(stdscr)) {
        case KEY_UP: case 'k': case 'K':
            p1.p.y--;
            break;

        case KEY_DOWN: case 'j': case 'J':
            p1.p.y++;
            break;

        case KEY_LEFT: case 'h': case 'H':
            p1.p.x--;
            break;

        case KEY_RIGHT: case 'l': case 'L':
            p1.p.x++;
            break;
        
        default:
            pselect(1, &rfds, NULL, NULL, &length, NULL);
    }
    return;
}

void new_point(void)
{
    while (1) {
        c.x = rand() % m.x+1;
        c.y = rand() % m.y+1;
        if ((c.x > 0 && c.x < m.x) && (c.y > 1 && c.y < m.y))
            break;
    }
}

int main()
{
    srand(time(0));
    int ch, move, score = 0;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, true);

    WINDOW *win = newwin(0, 0, 0, 0);

    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = '|';
    top = bottom = '-';
    tlc = brc = trc = blc = '+';

    getmaxyx(stdscr, m.y, m.x);

    move = MAX(m.x, m.y);
    p2.p.x = m.x-1;
    
    /* First Generation New Point */
   new_point();

    while(1) {
        key_event();
        getmaxyx(win, m.y, m.x);
        wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
        wprintw(win, "SCORE / MY: %d\tENEMY: %d", p1.win, p2.win);
  
        mvwaddch(win, p1.p.y, p1.p.x, 'o');
        mvwaddch(win, p2.p.y, p2.p.x, 'm');
        mvwaddch(win, c.y, c.x, 'x');

        /* Algorithm Control */
        if (abs(p2.p.x-c.x) > abs(p2.p.y-c.y)) {
            if (p2.p.x < c.x)
                p2.p.x++;
            else if (p2.p.x > c.x)
                p2.p.x--;
        } else {
            if (p2.p.y < c.y)
                p2.p.y++;
            else if (p2.p.y > c.y)
                p2.p.y--;
        }

        /* Field Boundaries */
        if (p1.p.x < 1)
            p1.p.x++;
        else if (p1.p.x >= m.x-1)
            p1.p.x--;
        
        if (p1.p.y < 2)
            p1.p.y++;
        else if (p1.p.y >= m.y-1)
            p1.p.y--;

        /* Generation New Point */
        if (p1.p.x == c.x && p1.p.y == c.y) {
           p1.win++;
           new_point();
        }
        if (p2.p.x == c.x && p2.p.y == c.y) {
            p2.win++;
            new_point();
        }

        usleep(10000);

        /* Break Program */
        if (p1.win >= LIMIT) {
            clear();
            mvprintw(m.y/2,(m.x-7)/2,"YOU WIN");
            refresh();
            sleep(2);
            break;

        }  
        if (p2.win >= LIMIT) {
            clear();
            mvprintw(m.y/2,(m.x-8)/2,"YOU LOSE");
            refresh();
            sleep(2);
            break;
        }

        wrefresh(win);
        werase(win);
    }
    endwin();
}