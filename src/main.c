#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "../includes/window.h"
#include "../includes/reader.h"

#include <ncurses.h>

SDL_Window* window = NULL;
BMP_FILE* file = NULL;
DIR* imageDir = NULL;

int main(){

    imageDir = CheckIfImageDir();

    file = getFile("../image/blue.bmp");

    window = CreateWindow(file->width,file->height);

    RenderImage(file,window);

    if(imageDir != NULL)
        closedir(imageDir);

    return 0;
}