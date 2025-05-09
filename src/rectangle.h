#ifndef REC_H
#define REC_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <iostream>

class Rectangle{
    public:
        int pos_x;
        int pos_y;
        int width;
        int height;
        int window_width;
        int window_height;
        
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

        Rectangle (int pos_x, int pos_y, int width, int height):
        pos_x(pos_x), pos_y(pos_y), width(width), height(height){}

        void draw(Uint8 border_color_R, Uint8 border_color_G, Uint8 border_color_B, Uint8 border_color_alpha, Uint8 fill_color_R, Uint8 fill_color_G, Uint8 fill_color_B, Uint8 fill_color_alpha, SDL_Renderer *rec_render, int window_width, int window_height){
            SDL_RenderClear(rec_render);
            rectangle.w = 250;
            rectangle.h = 250;
            // center the rectangle
            rectangle.x = window_width/2 - (rectangle.w/2);
            rectangle.y = window_height/2 - (rectangle.h/2);
        
            SDL_SetRenderDrawColor(rec_render, 255, 255, 255, 255);
            SDL_RenderDrawRect(rec_render, &rectangle); // make the outline
            SDL_RenderFillRect(rec_render, &rectangle); // fill the shape
            SDL_SetRenderDrawColor(rec_render, 0, 0, 0, 255);
        
            SDL_RenderPresent(rec_render);
        }
        SDL_Rect return_sdl_rect_type(){
            return rectangle;
        }
};

#endif