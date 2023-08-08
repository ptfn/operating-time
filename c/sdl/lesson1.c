#include <SDL2/SDL.h>

/* Size Window */
const int WIDTH = 640;
const int HEIGHT = 480;

int main(int argc, char *argv[])
{
    /* Init SDL (EVERYTHING) */
    if ( SDL_Init(SDL_INIT_EVERYTHING) != 0 ) {
        return 1;
    }

    /* Init Window and Surface */
    SDL_Surface* screen_surface = NULL;
    SDL_Window* window = NULL;

    /* Name and Position and  Size Window */
    window = SDL_CreateWindow("Hello, SDL!", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        return 1;
    }

    /* Surface Fill */
    screen_surface = SDL_GetWindowSurface(window);
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 255, 0));
    SDL_UpdateWindowSurface(window);

    /* Bye! Quit */
    SDL_Delay(5000);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
