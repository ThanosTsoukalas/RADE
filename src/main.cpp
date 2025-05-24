#include <iostream>
#include <ctime>

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>

#include "RADE/window.h"
#include "RADE/rectangle.h"

int WIDTH = 600, HEIGHT = 800;

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    Window window("Game", SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    window.initialize();

    SDL_Renderer *renderer = SDL_CreateRenderer(window.return_sdl_window_type(), -1, SDL_RENDERER_ACCELERATED);

    Rectangle rect(0, 0, 250, 250, true);

    SDL_Event event;

    bool running = true;
    
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
                rect.registerEvents(event);
            }
        }
        rect.draw(255, 255, 255, 255, 255, 255, 255, 255, renderer, WIDTH, HEIGHT);
    }

    return 0;
}