#include <ncurses.h>

int main()
{	int ch;

	initscr();			
	/* raw();*/
	keypad(stdscr, TRUE);
	noecho();	

    printw("Type any character to see it in bold\n");
    while (1) {
        ch = getch();	
        printw("The pressed key is %d\n", ch);
        refresh();
    }
	endwin();

	return 0;
}
