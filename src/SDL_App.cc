#include "SDL_App.h"

/* All SDL App's need this */
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include "GameObject.h"
#include "Tank.h"

void SDL_App::init(){
    printf("Initializing SDL.\n");
    
    /* Initialize defaults, Video and Audio */
    SDL_Window* window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);  // Initialize SDL2
    IMG_Init(IMG_INIT_PNG);

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    // Select the color for drawing. It is set to red here.
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Clear the entire screen to our selected color.
    SDL_RenderClear(renderer);

    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.
    SDL_RenderPresent(renderer);

    printf("SDL initialized.\n");

    // The window is open: could enter program loop here (see SDL_PollEvent())



    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example



}

SDL_Texture* SDL_App::loadTexture(const char* text, int* width, int* height){
    SDL_Surface* img = IMG_Load(text);

    if(!img)    printf("Error loading image: %s\n", (char const*)SDL_GetError());

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, img);

    if(!texture) printf("Error creating texture: %s\n", (char const*)SDL_GetError());

    *width = img->w; *height = img->h;

    SDL_FreeSurface(img); img = nullptr;

    return texture;
}

void SDL_App::render(GameObject* _go)
{
    _go->render();
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

// We can add scenes instead of these if it gets bigger
void SDL_App::initGObjs(){
    const char* tex = "../resources/tank.png";
    Tank* tank = new Tank(tex, 300,300, 100, this);
    
}

void SDL_App::addGO(GameObject* go){
    gObjs.push_back(go);
}

void SDL_App::gameLoop() {
    bool exit = false;
    while(!exit){
        // SDL_Event event;
        // // Handle all Events
        // while (SDL_PollEvent(&event)) { 
        for(auto it = gObjs.cbegin(); it != gObjs.cend(); ++it){
            (*it)->update();
            (*it)->render();
        }            
        // }
        // //handle input
    }
};

SDL_App::~SDL_App(){
    for(int i = 0; i < gObjs.size(); i++)
        delete gObjs[i];
    gObjs.clear();

    SDL_DestroyRenderer(renderer);
    renderer = nullptr;

    IMG_Quit();
    SDL_Quit();
}