#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX(a, b) (a > b ? a : b)
#define DELAY 30000
#define MOVE  15

typedef struct {
    int x;
    int y;
} Point;

int main()
{
    srand(time(0));
    int ch, move, score = 0;
    Point p1 = {0, 1}, p2 = {0, 1}, m = {0, 0}, c = {0, 0};

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);

    getmaxyx(stdscr, m.y, m.x);

    move = MAX(m.x, m.y);
    // p2.x = m.x-1;
    
    /* First Generation New Point */
    while (1) {
        c.x = rand() % m.x+1;
        c.y = rand() % m.y+1;
        if ((c.x >= 0 && c.x <= m.x) && (c.y >= 1 && c.y <= m.y))
            break;
    }

    while(1) {
        clear();
        printw("SCORE: %d\tMOVE: %d", score, move);
        // mvprintw(p1.y, p1.x, "o");
        mvprintw(p2.y, p2.x, "o");
        mvprintw(c.y, c.x, "x");
        
        /* My Control */
        // ch = getch();

        // switch (ch) {
        //     case 259: p1.y--; break;
        //     case 258: p1.y++; break;
        //     case 260: p1.x--; break;
        //     case 261: p1.x++; break;
        //     default: break;
        // }

        /* Algorithm Control */
        if (abs(p2.x-c.x) > abs(p2.y-c.y)) {
            if (p2.x < c.x)
                p2.x++;
            else if (p2.x > c.x)
                p2.x--;
        } else {
            if (p2.y < c.y)
                p2.y++;
            else if (p2.y > c.y)
                p2.y--;
        }

        /* Field Boundaries */
        if (p1.x < 0)
            p1.x++;
        else if (p1.x >= m.x)
            p1.x--;
        
        if (p1.y < 1)
            p1.y++;
        else if (p1.y >= m.y)
            p1.y--;

        /* Generation New Point */
        if ((p1.x == c.x && p1.y == c.y) || (p2.x == c.x && p2.y == c.y)) {
            score++;
            // move += MOVE;
            move += MOVE + (MAX(m.x, m.y) / 3);
            while (1) {
                c.x = rand() % m.x+1;
                c.y = rand() % m.y+1;
                if ((c.x > 0 && c.x < m.x) && (c.y > 1 && c.y < m.y))
                    break;
            }
        }

        /* Break Program */
        if (move > 0)
            move--;
        else {
            clear();
            mvprintw(m.y/2,(m.x-8)/2,"YOU LOSE");
            refresh();
            usleep(DELAY);
            break;refresh();
        }
        refresh();
        usleep(DELAY);
    }
    endwin();
}