#include <stdbool.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#define DELAY 1e5

typedef struct {
    uint8_t x, y;
} point;

void generate_arr(uint8_t x, uint8_t y, bool arr[x][y])
{
    for (uint8_t i = 0; i < x; i++)
        for (uint8_t j = 0; j < y; j++)
            arr[i][j] = false;
}

void copy_array(uint8_t n, uint8_t m, bool main[n][m], bool copy[n][m])
{
    for (uint8_t i = 0; i < n; i++)
        for (uint8_t j = 0; j < m; j++)
            copy[i][j] = main[i][j];
}

void stop(uint8_t n, uint8_t m, bool grid[n][m], WINDOW *win)
{
    bool run = true;
    wattron(win, A_STANDOUT);
    mvwprintw(win, m-1, 0, "STOP");
    wattroff(win, A_STANDOUT);

    while (run) {
        int c = wgetch(stdscr); 
                
        if (c == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                if (event.bstate && BUTTON1_PRESSED) {
                    mvwaddch(win, event.y, event.x, '#');
                    grid[event.x][event.y] = 1;
                } else if (event.bstate && BUTTON4_PRESSED) {
                    mvwaddch(win, event.y, event.x, '.');
                    grid[event.x][event.y] = 0;
                }
            }
        } else {
            switch (c) {
                case 's': case 'S':
                    run = false;
                    break;
               default:
                    break;
            } 
        }
        wrefresh(win);
    }
}

void key_event(uint8_t n, uint8_t m, bool grid[n][m], bool *run, WINDOW *win)
{
    struct timespec length = {0, 0};
    uint16_t c;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);

    switch(c = wgetch(stdscr)) {
        case 'q': case 'Q':
            *run = false;
            break;

        case 's': case 'S':
            stop(n, m, grid, win);
            break;

        default:
            pselect(1, &rfds, NULL, NULL, &length, NULL);
    }
}


int main()
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, true);

    WINDOW *win = newwin(0, 0, 0, 0);

    mousemask(ALL_MOUSE_EVENTS, NULL);

    point max = {0, 0};
    getmaxyx(stdscr, max.y, max.x);

    bool grid[max.x][max.y];
    bool copy[max.x][max.y];
    bool run = true;
    
    generate_arr(max.x, max.y, grid);

    while (run) {
        /* Print Array */
        for (uint8_t x = 0; x < max.x; x++)
            for (uint8_t y = 0; y < max.y; y++)
                if (grid[x][y]) mvwaddch(win, y, x, '#');
                else mvwaddch(win, y, x, '.');  
       
        copy_array(max.x, max.y, grid, copy);

        /* New generation */
        for (uint8_t x = 0; x < max.x; x++) {
            for (uint8_t y = 0; y < max.y; y++) {
                uint8_t neighbor = 0;
                neighbor = grid[x][(y-1)%max.y] + grid[x][(y+1)%max.y] +
                           grid[(x-1)%max.x][y] + grid[(x+1)%max.x][y] +
                           grid[(x-1)%max.x][(y-1)%max.y] + grid[(x-1)%max.x][(y+1)%max.y] +
                           grid[(x+1)%max.x][(y-1)%max.y] + grid[(x+1)%max.x][(y+1)%max.y];

                if (grid[x][y]) {
                    if (neighbor < 2 || neighbor > 3) copy[x][y] = false;
                } else {
                    if (neighbor == 3) copy[x][y] = true;
                }
            }
        }
        copy_array(max.x, max.y, copy, grid);
        key_event(max.x, max.y, grid, &run, win);
        usleep(DELAY);
        wrefresh(win);
        werase(win);
    }

    endwin();
    return 0;
}
