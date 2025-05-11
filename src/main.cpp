#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include "window.h"
#include "rectangle.h"

// this is my screen resolution (HP elite x2)
int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    Window window("Game", SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    window.initialize();

    SDL_Renderer *renderer = SDL_CreateRenderer(window.return_sdl_window_type(), -1, SDL_RENDERER_ACCELERATED);

    Rectangle rect(0, 0, 250, 250);

    bool running = true;
    
    SDL_Event event;

    // drawing and event handling loop
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
                SDL_DestroyWindow(window.return_sdl_window_type());
                SDL_Quit();
                return EXIT_SUCCESS;
            }
            else {
                window.registerEvents(event);
            }
        }
        rect.draw(255, 255, 255, 255, 255, 255, 255, 255, renderer, WIDTH, HEIGHT);
    }

    return 0;
}