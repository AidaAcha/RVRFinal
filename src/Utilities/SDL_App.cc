#include "SDL_App.h"

/* All SDL App's need this */
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include "Game.h"
#include "GameObject.h"
#include "Tank.h"

void SDL_App::init(Game* _game){
    printf("Initializing SDL.\n");
    
    /* Initialize defaults, Video and Audio */
    SDL_Window* window;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);  // Initialize SDL2
    IMG_Init(IMG_INIT_PNG);

    windowH = 480; windowW = 640;

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        windowW,                               // width, in pixels
        windowH,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    // Select the color for drawing.
    SDL_SetRenderDrawColor(renderer, 140, 195, 70, 255);

    // Clear the entire screen to our selected color.
    SDL_RenderClear(renderer);

    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.

    printf("SDL initialized.\n");

    game = _game;

}

SDL_Texture* SDL_App::loadTexture(const char* text, int& width, int& height){
    SDL_Surface* img = IMG_Load(text);

    if(!img)    printf("Error loading image: %s\n", (char const*)SDL_GetError());

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, img);

    if(!texture) printf("Error creating texture: %s\n", (char const*)SDL_GetError());

    width = img->w; height = img->h;

    SDL_FreeSurface(img); img = nullptr;

    return texture;
}

void SDL_App::renderPresent(){
    SDL_RenderPresent(renderer);
}

void SDL_App::clearWindow(){
    // Select the color for drawing. It is set to red here.
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Clear the entire screen to our selected color.
    SDL_RenderClear(renderer);
}

bool SDL_App::intersectRects(SDL_Rect& rect1, SDL_Rect& rect2) {    
    Vector2 v0 = Vector2(rect1.x, rect1.y);
    Vector2 v1 = Vector2(rect1.x + rect1.w - 1, rect1.y);
    Vector2 v2 = Vector2(rect1.x, rect1.y + rect1.h - 1);
    Vector2 v3 = Vector2(rect1.x + rect1.w - 1, rect1.y + rect1.h - 1);

    // Comprueba si alguna esquina del collider del fantasma esta dentro del collider
    return (insideRect(v0, rect2) || insideRect(v1, rect2) ||
            insideRect(v2, rect2) || insideRect(v3, rect2));
}

bool SDL_App::insideRect(Vector2& pos, SDL_Rect& rect) {
    return (pos.x >= rect.x && pos.y >= rect.y &&
        pos.x < rect.x + rect.w && pos.y < rect.y + rect.h);
}

SDL_App::~SDL_App(){
    delete game;

    SDL_DestroyRenderer(renderer);
    renderer = nullptr;

    IMG_Quit();
    SDL_Quit();
}