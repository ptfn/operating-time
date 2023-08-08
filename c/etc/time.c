/*  String Time
 *  0-2 -   Day Week
 *  4-6 -   Month
 *  8-9 -   Day In Month
 *  11-18 - Hour / Minute / Second
 *  20-24 - Year
 */

#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define DELAY 100000

int main()
{
    struct tm *ptr;
    char *str;
    time_t t;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);

    while (1) {
        clear();
        /* String Update */
        t = time(NULL);
        ptr = localtime(&t);
        str = asctime(ptr);
    
        for (short i = 0; i <= 18; i++)
            printw("%c", str[i]);

        refresh();
        usleep(DELAY);
    }
    
    return 0;
}

