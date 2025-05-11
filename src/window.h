#ifndef WIN_H
#define WIN_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

class Window{
public:
    const char *TITLE;
    int pos; // window position
    int width;
    int height;
    Uint32 special_flags;
    SDL_Window *t_window;

    Window (const char *TITLE, int pos, int width, int height, Uint32 special_flags)
    :  TITLE(TITLE), pos(pos), width(width), height(height), special_flags(special_flags){}

    int initialize(){
        t_window = SDL_CreateWindow(TITLE, pos, pos, width, height, special_flags);
        if (NULL == t_window){ 
            std::cout << "'window.h' : Could not create window. ERR_MSG: " << SDL_GetError() << std::endl;
            return 1;
        }
        return 0;
    }

    void registerEvents(SDL_Event &event) {
        if (event.type == SDL_KEYDOWN) {
            // if (event.key.keysym.sym == SDLK_LEFT) {
            //     pos_x -= 10; // Move rectangle left
            // } else if (event.key.keysym.sym == SDLK_RIGHT) {
            //     pos_x += 10; // Move rectangle right
            // } else if (event.key.keysym.sym == SDLK_UP) {
            //     pos_y -= 10; // Move rectangle up
            // } else if (event.key.keysym.sym == SDLK_DOWN) {
            //     pos_y += 10; // Move rectangle down
            // }

            std::cout << "Key press detected." << std::endl;
        }
    }
    
    SDL_Window *return_sdl_window_type(){
        return t_window;
    }
};
// fix that shit
#endif