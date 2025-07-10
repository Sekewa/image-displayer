#include <stdio.h>
#include <stdlib.h>
#include "../includes/reader.h"
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


int main(){

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr,"Erreur d'initialisation de SDL: %s\n",SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Image Displayer",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if(!window) {
        fprintf(stderr,"Erreur lors de la creation de la fenetre: %s\n",SDL_GetError());
        SDL_Quit();
        return 1;
    }

    int quit = 0;
    SDL_Event event;

    while(!quit) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        SDL_Delay(16);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    getFile("../image/red.bmp");

    return 0;
}