#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>

#define DELAY_LOOP 1e3
#define DELAY_MSG  1e6
#define WIN        1e6

typedef struct {
    struct {
        uint64_t price;
        uint8_t  score;
    } increase;

    struct {
        uint64_t price;
        uint8_t  score;
    } multiply;
    
    struct {
        uint64_t price;
        uint8_t  score;
    } eraction;


    struct {
        uint64_t price_all;
        uint64_t counter;
        uint64_t add;
    } main;

    bool run; 
} Click;


int main()
{
    Click click = {{50, 1}, {250, 2}, {5000, 2}, {10000, 0, 1}, true};
    uint16_t xMax, yMax;
    int8_t i, j = 0;
    char list[4][20] = {"Addition", "Multiplication", "Erection", "Increase All"};
    char item[50];

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(false);

    mousemask(BUTTON1_CLICKED, NULL); 

    while (click.run) {
        clear();
        
        uint64_t price[4] = {click.increase.price, 
                             click.multiply.price, 
                             click.eraction.price, 
                             click.main.price_all};
                
        for (i = 0; i < 4; i++) {
            if (i == j)
                wattron(stdscr, A_STANDOUT); 
                
            sprintf(item, "%-4s - %ld", list[i], price[i]);
            mvwprintw(stdscr, i + 2, 2, "* %s", item);
            wattroff(stdscr, A_STANDOUT);
        }

        box(stdscr, 0, 0);
        getmaxyx(stdscr, yMax, xMax);
        mvprintw(0, 1, "SCORE: %ld ADD: %ld I: %d M: %d E: %d",
                 click.main.counter, click.main.add, 
                 click.increase.score, click.multiply.score, click.eraction.score);

        uint16_t ch = wgetch(stdscr);
                 
        if (ch == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                if (event.bstate && BUTTON1_CLICKED) {
                    click.main.counter += click.main.add;
                }
            }
        } else {
            switch (ch) {
                case 'q': case 'Q':
                    click.run = false;
                    break;

                case 10:
                    if (j == 0) {
                        if (click.main.counter >= click.increase.price) {
                            click.main.add += click.increase.score;
                            click.main.counter -= click.increase.price;
                            click.increase.price *= 1.5;
                            mvprintw(yMax-1, 1, "You buy increase!");
                        } else {
                            mvprintw(yMax-1, 1, "You don't have enough points!");
                        }
                    } else if (j == 1) {
                        if (click.main.counter >= click.multiply.price) {
                            click.main.add *= click.multiply.score;
                            click.main.counter -= click.multiply.price;
                            click.multiply.price *= 4;
                            mvprintw(yMax-1, 1, "You buy multiply!");
                        } else {
                            mvprintw(yMax-1, 1, "You don't have enough points!");
                        }   
                    } else if (j == 2) {
                        if (click.main.counter >= click.eraction.price) {
                            click.main.add = (uint64_t)pow(click.main.add, click.eraction.score);
                            click.main.counter -= click.eraction.price;
                            click.eraction.price *= 10;
                            mvprintw(yMax-1, 1, "You buy eraction!");
                        } else {
                            mvprintw(yMax-1, 1, "You don't have enough points!");
                        } 
                    } else {
                        if (click.main.counter >= click.main.price_all) {
                            click.increase.score++;
                            click.multiply.score++;
                            click.eraction.score++;
                            click.main.counter -= click.main.price_all;
                            click.main.price_all *= 15;
                            mvprintw(yMax-1, 1, "You buy increase all!");
                        } else {
                            mvprintw(yMax-1, 1, "You don't have enough points!");
                        } 
                    }

                    refresh();
                    usleep(DELAY_MSG);
                    break;      

                case KEY_UP:
                    j--;
                    j = (j < 0) ? 3 : j;
                    break;
                
                case KEY_DOWN:
                    j++;
                    j = (j > 3) ? 0 : j;
                    break;

                default:
                    click.main.counter += click.main.add;
                    break;
            }
        }
        if (click.main.counter >= WIN) {
            clear();
            mvprintw(yMax/2,(xMax-7)/2, "YOU WIN");
            refresh();
            sleep(2);
            click.run = false;
        }
        usleep(DELAY_LOOP);
        refresh();
    }

    endwin();
    return 0;
}