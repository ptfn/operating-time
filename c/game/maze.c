#include <ncurses.h>
#include <unistd.h>

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned long   u32;

int main()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);

    u16 x, y, h, w;
    x = y = h = w = 0;

    WINDOW* win = newwin(x, y, h, w);
    box(win, 0, 0);
    wresize(win, 8, 15);
    wrefresh(win);

    u8 lt, rt, tp, bm, tl, tr, bl, br;
    lt = rt = '|';
    tp = bm = '-';
    tl = br = tr = bl = '+';

    while (true) {
        wborder(win, lt, rt, tp, bm, tl, tr, bl, br);
        mvwaddstr(win, 2, 4, "HI");
        mvprintw(10, 10, "HH");
        
        u16 ch = getch();

        switch (ch) {
            case 259: mvwin(win, x--, y); break;
            case 258: mvwin(win, x++, y); break;
            case 260: mvwin(win, x, y--); break;
            case 261: mvwin(win, x, y++); break;
            default: break;
        }
        usleep(1000);
        wrefresh(win);
    }
    endwin();
    return 0;
}