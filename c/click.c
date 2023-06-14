#include <ncurses.h>

int main()
{
    long win = 0;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    while (1) {
        int c = wgetch(stdscr);

        if (c == '\n')
            break;
                
        if (c == ERR) { 
            mvprintw(0, 1, "Error!");
        } else if (c == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                win++;
            } else {
                mvprintw(0, 1, "Error!");
            }
        } else {
            win++;
        }

        mvprintw(0, 0, "%ld", win);
    }

    endwin();
    return 0;
}