#ifndef REC_H
#define REC_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <iostream>

class Rectangle{
    public:
        int pos_x;
        int pos_y;
        int width;
        int height;
        int window_width;
        int window_height;
        bool is_centered;
        
        Uint8 border_color_R;
        Uint8 border_color_G;
        Uint8 border_color_B;
        Uint8 border_color_alpha;
        Uint8 fill_color_R;
        Uint8 fill_color_G;
        Uint8 fill_color_B;
        Uint8 fill_color_alpha;
        SDL_Renderer *rec_renderer;
        SDL_Rect rectangle;

        Rectangle (int pos_x, int pos_y, int width, int height, bool is_centered):
        pos_x(pos_x), pos_y(pos_y), width(width), height(height), is_centered(is_centered){}

        void draw(Uint8 border_color_R, Uint8 border_color_G, Uint8 border_color_B, Uint8 border_color_alpha, Uint8 fill_color_R, Uint8 fill_color_G, Uint8 fill_color_B, Uint8 fill_color_alpha, SDL_Renderer *rec_render, int window_width, int window_height){
            SDL_RenderClear(rec_render);
            rectangle.w = 250;
            rectangle.h = 250;

            if (is_centered == true){
                pos_x = (window_width/2) - (width/2);
                pos_y = (window_height/2) - (height/2);
            }

            rectangle.x = pos_x;
            rectangle.y = pos_y;
            SDL_SetRenderDrawColor(rec_render, 255, 255, 255, 255);
            SDL_RenderDrawRect(rec_render, &rectangle); // make the outline
            SDL_RenderFillRect(rec_render, &rectangle); // fill the shape
            SDL_SetRenderDrawColor(rec_render, 0, 0, 0, 255);
            SDL_RenderPresent(rec_render);
        }

        void registerEvents(SDL_Event &event) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_LEFT) {
                    pos_x = pos_x - 10;
                } else if (event.key.keysym.sym == SDLK_RIGHT) {
                   pos_x = pos_x + 10;
                } else if (event.key.keysym.sym == SDLK_UP) {
                    pos_y = pos_y - 10;
                } else if (event.key.keysym.sym == SDLK_DOWN) {
                    pos_y = pos_y + 10;
                }
            }
        }

        SDL_Rect return_sdl_rect_type(){
            return rectangle;
        }
};

#endif