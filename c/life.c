#include <stdbool.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdint.h>

#define DELAY 300000

typedef struct {
    uint8_t x;
    uint8_t y;
} Size;

void generate_arr(uint8_t x, uint8_t y, bool arr[][y])
{
    for (uint8_t i = 0; i < x; i++)
        for (uint8_t j = 0; j < y; j++)
            arr[i][j] = false;
}

bool cell_death(uint8_t number)
{
    if (number == 2 || number == 3)
        return true;
    else
        return false;
}

bool cell_birth(uint8_t number)
{
    if (number == 3)
        return true;
    else
        return false;
}

int main()
{
    initscr();
    noecho();
    curs_set(FALSE);

    Size max = {0, 0};
    getmaxyx(stdscr, max.y, max.x);
    bool cells[max.x][max.y];
    generate_arr(max.x, max.y, cells);
    
    /* Raw Data */
    /* Line */
    cells[2][1] = true;
    cells[2][2] = true;
    cells[2][3] = true;
    /* Cube */
    // cells[1][1] = true;
    // cells[1][2] = true;
    // cells[2][1] = true;
    // cells[2][2] = true;

    while (true) {
        clear();
        for (uint8_t i = 0; i < max.x; i++)
            for (uint8_t j = 0; j < max.y; j++)
                if (cells[i][j])
                    mvprintw(j, i, "o");
                else
                    mvprintw(j, i, ".");

        /* New generation */
        for (uint8_t i = 0; i < max.x; i++) {
            for (uint8_t j = 0; j < max.y; j++) {
                uint8_t number = 0;

                for (int8_t in = -1; in <= 1; in++)
                    for (int8_t jn = -1; jn <= 1; jn++)
                        if (!(in == 0 && jn == 0))
                            if (cells[i+in][j+jn])
                                number++;

                if (!(i == 0 && j == 0) && !(i == max.x-1 && j == max.y-1))
                    if (cells[i][j])
                        if (!(cell_death(number)))
                            cells[i][j] = false;
                    else
                        if (cell_birth(number))
                        cells[i][j] = true;
            }
        }

        refresh();
        usleep(DELAY);
    }

    endwin();
    return 0;
}