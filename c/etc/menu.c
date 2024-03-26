#include <ncurses.h>
#include <unistd.h>

int main(void)
{
    initscr();
    mvprintw(10, 10, "Hello");
    refresh();
    sleep(2);
    endwin();
}
