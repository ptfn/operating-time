#include <ncurses.h>
#include <unistd.h>

int main(void)
{    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    curs_set(false);

    MEVENT event;
    int ch;

    mousemask(ALL_MOUSE_EVENTS, NULL);

    while (1) {
        clear();
        switch ((ch = wgetch(stdscr))) {
            case KEY_MOUSE:
                if (getmouse(&event) == OK) {
                    mvprintw(0, 0, "%d", event.bstate);
                    if (event.bstate & BUTTON1_PRESSED)
                        mvprintw(1, 1, "1");
                    else if (event.bstate & BUTTON2_PRESSED)
                        mvprintw(1, 1, "2");
                    else if (event.bstate & BUTTON3_PRESSED)
                        mvprintw(1, 1, "3");
                    else if (event.bstate & BUTTON4_PRESSED)
                        mvprintw(1, 1, "4");
                    else if (event.bstate & BUTTON5_PRESSED)
                        mvprintw(1, 1, "5");
                    
                } break;
            default:
                mvprintw(0, 0, "%d", ch);
                break;
        }
        refresh();
        sleep(2);
    }
    return 0;
}
