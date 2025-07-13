#include "../includes/window.h"

SDL_Window* CreateWindow(int WIDTH, int HEIGHT) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr,"Erreur d'initialisation de SDL: %s\n",SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Image Displayer",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if(!window) {
        fprintf(stderr,"Erreur lors de la creation de la fenetre: %s\n",SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    return window;
}

void RenderImage(BMP_FILE* FILEBMP,SDL_Window* WINDOW) {

    FILE* out = fopen("../out.txt","w+");

    int quit = 0;
    SDL_Event event;

    SDL_Surface* surface = SDL_GetWindowSurface(WINDOW);

    int pixelNumber = FILEBMP->width * FILEBMP->height;

    Uint32* pixels = (Uint32 *) surface->pixels;

    if(feof(FILEBMP->fileptr) == 0) {
        for(int i = 0; i < pixelNumber;i++) {
            Uint8 b = fgetc(FILEBMP->fileptr);
            Uint8 g = fgetc(FILEBMP->fileptr);
            Uint8 r = fgetc(FILEBMP->fileptr);
            pixels[i] = SDL_MapRGB(surface->format,r,g,b);
            Uint8 f = fgetc(FILEBMP->fileptr);

            // debug file for seeing if the value are inverted
            fprintf(out,"r : %i, g : %i, b : %i, f : %i\n",r,g,b,f);
        }
        SDL_UpdateWindowSurface(WINDOW);
    }

    // end the WINDOW when cross clicked
    while(!quit) {

        

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        SDL_Delay(16);
    }

    SDL_DestroyWindow(WINDOW);
    SDL_Quit();
}