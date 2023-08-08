#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

SDL_Window *win = NULL;
SDL_Surface *scr = NULL;
SDL_Surface *smile = NULL;

int init()
{
    /* Init and Create Windows */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    win = SDL_CreateWindow("Smile My Friend!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (win == NULL) {
        return 1;
    }

    scr = SDL_GetWindowSurface(win);

    return 0;
}

int load() 
{
    /* Load Picture */
    smile = SDL_LoadBMP("random-colors.bmp");

    if (smile == NULL) {
        return 1;
    }

    return 0;
}

void quit() 
{
    /* Clear Surface and Destoy Window */
    SDL_FreeSurface(smile);    
    SDL_DestroyWindow(win);
    SDL_Quit();
}

int main (int argc, char **args) 
{
    if (init()) {
        return 1;
    }

    if (load()) {
        return 1;
    }

    /* Display Picture and Updated */
    SDL_BlitSurface(smile, NULL, scr, NULL);
    SDL_UpdateWindowSurface(win);
    SDL_Delay(2000);
    quit();

    return 0;
};