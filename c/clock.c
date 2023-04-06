#include <stdbool.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define DELAY 13500
#define WORK  1500
#define BREAK 300
bool run = true;

const bool number[][15] =
{
    {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1},
    {0,0,1,0,0,1,0,0,1,0,0,1,0,0,1},
    {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1},
    {1,1,1,0,0,1,1,1,1,0,0,1,1,1,1},
    {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1},
    {1,1,1,1,0,0,1,1,1,0,0,1,1,1,1},
    {1,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
    {1,1,1,0,0,1,0,0,1,0,0,1,0,0,1},
    {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1},
    {1,1,1,1,0,1,1,1,1,0,0,1,1,1,1},
};

void key_event(void)
{
    int c;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);

    switch(c = wgetch(stdscr)) {
        case 'q': case 'Q': run = false; break;
        default: break;
    }
    return;
}

void draw_colon(uint16_t x, uint16_t y)
{
    for (uint16_t i = y; i < 5+y;  i++) {
        if (i-y == 1 || i-y == 3)
            mvprintw(i, x, "//");
    }
}

void draw_number(uint8_t n, uint16_t x, uint16_t y)
{
    for (uint16_t i = y, iter = 0; i < 5+y;  i++)
        for (uint16_t j = x; j < 6+x; j++) {
            if (j % 2 != 0) {
                if (number[n][iter])
                    mvprintw(i, j, "//");
                    /* Need colors number */
                iter++;
            }
        }
}

void format(uint32_t time)
{
    uint8_t second = time % 60;
    uint8_t minute = time / 60;

    draw_number(minute/10, 0, 0);
    draw_number(minute%10, 8, 0);
    draw_colon(16, 0);
    draw_number(second/10, 18, 0);
    draw_number(second%10, 26, 0);
}

void notify(char *message)
{
    char command[50] = "notify-send ";
    strcat(command, message);
    system(command);
}

int main()
{
    clock_t start, end;
    bool state = false; // 0 - work 1 -break
    start = clock();

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);

    while (true) {
        clear();
        key_event();
        end = (clock() - start) / 1000 / 10;

        if (state)
            if (BREAK-end <= 0) {
                notify("'Tomato Clock' 'Work time 25 minutes!'");
                format(BREAK - end);
                state = false;
                start = clock();
            } else {
                format(BREAK - end);
            }
        else
            if (WORK-end <= 0) {
                notify("'Tomato Clock' 'Break time 5 minutes!'");
                state = true;
                start = clock();
                format(WORK-end);
            } else {
                format(WORK - end);
            }
    
        if (!(run))
            break;

        refresh();
        usleep(DELAY);
    }
    endwin();
    
    return 0;
}
