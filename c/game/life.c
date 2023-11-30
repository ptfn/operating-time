#include <ncurses.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define DELAY 1e5
#define ENTER 10

typedef struct {
    uint16_t w, h;
} Size;

typedef struct {
    uint16_t x, y;
} Point;

static void init(void)
{
    initscr();
    noecho();
    keypad(stdscr, true);
    curs_set(false);
    nodelay(stdscr, true);

    use_default_colors();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    
    box(stdscr, 0, 0);
}

static void print_grid(WINDOW *win, Size s, bool grid[s.w][s.h])
{
    for (uint16_t i = 0; i < s.w; i++) {
        for (uint16_t j = 0; j < s.h; j++) {
            if (grid[i][j]) {
                wattron(win, COLOR_PAIR(1));
                printw("  ");
                wattroff(win, COLOR_PAIR(1));
            } else
                printw("  ");
        }
        printw("\n");
    }
}

static void generation(Size s, bool grid[s.w][s.h])
{
    bool copy[s.w][s.h];
    memset(copy, 0, sizeof(copy));

    for (uint16_t i = 0; i < s.w; i++) {
        for (uint16_t j = 0, n; j < s.h; j++, n = 0) {
            for (int16_t x = i - 1; x <= i + 1; x++)
                for (int16_t y = j - 1; y <= j + 1; y++)
                    if (grid[(x + s.w) % s.w][(y + s.h) % s.h]) n++;
            if (grid[i][j]) n--;
            copy[i][j] = (n == 3 || (n == 2 && grid[i][j]));
        }
    }

    for (uint16_t i = 0; i < s.w; i++)
        for (uint16_t j = 0; j < s.h; j++)
            grid[i][j] = copy[i][j];
}

static void key_event(Point *p, Size s, bool grid[s.w][s.h], bool *run)
{
    struct timespec length = {1, 0};
    uint16_t c;

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);

    switch(c = wgetch(stdscr)) {
        case 'q': case 'Q':
            *run = false;
            break;
        case KEY_UP: p->y--; break;
        case KEY_DOWN: p->y++; break;
        case KEY_RIGHT: p->x++; break;
        case KEY_LEFT: p->x--; break;
        case ENTER: grid[p->x][p->y] = 1; break;
        case 'n': case 'N': generation(s, grid); break;
        default:
            pselect(1, &rfds, NULL, NULL, &length, NULL);
    }
}

int main(void)
{
    init(); // Init Ncurses

    Size std, main; // Alloc Variables
    getmaxyx(stdscr, std.h, std.w);
    std.w = std.w / 2;

    Point mouse = {std.w/2, std.h/2}; // Position Mouse (keyboard)

    WINDOW *win = newwin(std.h-2, std.w-2, 1, 1); // Create Main Window
    getmaxyx(win, main.h, main.w);

    bool grid[main.w][main.h], run = true; // Create Grid Game
    memset(grid, 0, sizeof(grid));

    while (run) {
        wclear(win);

        wattron(win, COLOR_PAIR(1));
        print_grid(win, main, grid);
        wattroff(win, COLOR_PAIR(1));

        key_event(&mouse, main, grid, &run);
        mvwaddch(win, mouse.y, mouse.x, 'x');

        wrefresh(win);
        // usleep(DELAY);
    }
    endwin();

    return 0;
}
