#include "SDL_App.h"

#include <SDL2/SDL.h>  /* All SDL App's need this */
#include <stdio.h>

void SDL_App::init(){
    printf("Initializing SDL.\n");
    
    /* Initialize defaults, Video and Audio */
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) { 
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }

    printf("SDL initialized.\n");

}

SDL_App::~SDL_App(){
    SDL_Quit();
}