import curses

string = ""
stdscr = curses.initscr()
curses.echo()
stdscr.clear()

while True:
    string = stdscr.getstr(10, 0, 20)
    stdscr.addstr(0, 0, string)
    stdscr.refresh()
    stdscr.clear()
