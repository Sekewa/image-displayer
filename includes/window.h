#ifndef WINDOW_C_INCLUDE
#define WINDOW_C_INCLUDE

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

SDL_Window* CreateWindow(int WIDTH, int HEIGHT);

void RenderImage(BMP_FILE* FILE,SDL_Window* WINDOW);

#endif // WINDOW_C_INCLUDE