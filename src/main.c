#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "../includes/window.h"
#include "../includes/reader.h"

SDL_Window* window = NULL;
BMP_FILE* file = NULL;

int main(){

    file = getFile("../image/blue.bmp");

    window = CreateWindow(file->width,file->height);

    RenderImage(file,window);

    return 0;
}