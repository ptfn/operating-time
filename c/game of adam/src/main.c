#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to initialize the SDL2 library\n");
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);

    if(!window) {
        printf("Failed to create window\n");
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface) {
        printf("Failed to get the surface from the window\n");
        printf("SDL2 Error: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Surface *image = SDL_LoadBMP("../img/sample_640×426.bmp");

    if (!image) {
        printf("Failed to load image\n");
        printf("SDL2 Error: %s\n", SDL_GetError());
        return -1;
    }

    bool keep_window_open = true;

    while (keep_window_open) {
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0) {
            switch (e.type) {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }

            SDL_BlitScaled(image, NULL, window_surface, NULL);
            SDL_UpdateWindowSurface(window);
        }
    }
    SDL_FreeSurface(image);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
