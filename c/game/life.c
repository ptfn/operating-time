#include <stdbool.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define DELAY 1e5

typedef struct {
    uint16_t h, w;
} Size;

void copy_array(Size s, bool main[s.h][s.w], bool copy[s.h][s.w])
{
    for (uint16_t i = 0; i < s.h; i++)
        for (uint16_t j = 0; j < s.w; j++)
            copy[i][j] = main[i][j];
}

void stop(Size s, bool grid[s.h][s.w], WINDOW *win)
{
    bool run = true;
    wattron(win, A_STANDOUT);
    mvwprintw(win, s.w-1, 0, "STOP");
    wattroff(win, A_STANDOUT);

    while (run) {
        int c = wgetch(stdscr); 
                
        if (c == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                if (event.bstate && BUTTON1_PRESSED) {
                    if (event.x <= s.h && event.y <= s.w) {
                        mvwaddch(win, event.y-1, event.x-1, '#');
                        grid[event.x][event.y] = 1;
                    }
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

void key_event(Size s, bool grid[s.h][s.w], bool *run, WINDOW *win)
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
            stop(s, grid, win);
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
    mousemask(ALL_MOUSE_EVENTS, NULL);

    Size all, temp, swin;
    getmaxyx(stdscr, all.w, all.h);

    WINDOW *win = newwin(all.w-2, all.h-(int)(all.h/100.0*30), 1, 1);
    getmaxyx(win, swin.w, swin.h);

    bool grid[swin.h][swin.w];
    bool copy[swin.h][swin.w];
    bool run = true;

    memset(grid, 0, sizeof(grid)); 
    memset(copy, 0, sizeof(copy));

    while (run) {  
       getmaxyx(stdscr, temp.w, temp.h);

       if (temp.h != all.h || temp.w != all.w) {
            all = temp;
            wresize(win, all.w-2, all.h-(int)(all.h/100.0*30));
            getmaxyx(win, swin.w, swin.h);
       }

        /* Print Array */
        for (uint16_t x = 0; x < swin.h; x++)
            for (uint16_t y = 0; y < swin.w; y++)
                if (grid[x][y]) mvwaddch(win, y, x, '#');
                else mvwaddch(win, y, x, '.');  
       
        copy_array(swin, grid, copy);

        /* New generation */
        for (uint16_t x = 0; x < swin.h; x++) {
            for (uint16_t y = 0; y < swin.w; y++) {
                uint16_t neighbor = 0;
                neighbor = grid[x][(y-1)%swin.w] + grid[x][(y+1)%swin.w] +
                           grid[(x-1)%swin.h][y] + grid[(x+1)%swin.h][y] +
                           grid[(x-1)%swin.h][(y-1)%swin.w] + grid[(x-1)%swin.h][(y+1)%swin.w] +
                           grid[(x+1)%swin.h][(y-1)%swin.w] + grid[(x+1)%swin.h][(y+1)%swin.w];

                if (grid[x][y]) {
                    if (neighbor < 2 || neighbor > 3) copy[x][y] = false;
                } else {
                    if (neighbor == 3) copy[x][y] = true;
                }
            }
        }
        copy_array(swin, copy, grid);
        key_event(swin, grid, &run, win);
        usleep(DELAY);
        wrefresh(win);
        werase(win);
    }

    endwin();
    return 0;
}
