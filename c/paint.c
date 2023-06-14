#include <ncurses.h>
#include <stdbool.h>
#include <stdint.h>

// Add menu paint color and lines and background

void print_char(uint16_t x, uint16_t y, uint8_t color)
{
    wattron(stdscr, COLOR_PAIR(color));
    mvwaddch(stdscr, y, x, ' ');
    wattroff(stdscr, COLOR_PAIR(color));
}

int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    use_default_colors();
    start_color();
    curs_set(false);
    box(stdscr, 0, 0);

    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(7, COLOR_CYAN, COLOR_CYAN);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);

    bool run = true;
    uint8_t color = 1;

    while (run) {
        int c = wgetch(stdscr); 
                
        if (c == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                if (event.bstate && BUTTON2_PRESSED) {
                    print_char(event.x, event.y, color);
                }
            }
        } else {
            switch (c) {
                case 'q': case 'Q':
                    run = false;
                    break;curs_set(false);

                case 'c': case 'C':
                    clear();
                    break;

                case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8':
                    color = c - '0';
                    break;
           
               default:
                break;
            } 
        }
    }

    endwin();
    return 0;
}