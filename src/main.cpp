#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include "win.h"
#include "rectangle.h"

// this is my screen resolution (HP elite x2)
int WIDTH = 1920, HEIGHT = 1280;

int main (int argc, char *argv[]){

    SDL_Init(SDL_INIT_EVERYTHING);
    Window window("Game", SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN);
    window.initialize();

    // Actual code begins here
    SDL_Renderer *renderer = SDL_CreateRenderer(window.return_sdl_window_type(), -1, 0);
    Rectangle rect(0, 0, 250, 250);
    rect.draw(255, 255, 255, 255, 255, 255, 255, 255, renderer, WIDTH, HEIGHT);

    // Actual code ends here
    window.await_for_close();
    return 0;
}