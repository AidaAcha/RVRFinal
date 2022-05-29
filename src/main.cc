#include <iostream>
#include "SDL_App.h"

const int WIDTH = 800, HEIGHT = 600;

int main (int argc, char *argv[])
{
    SDL_App* app = new SDL_App();
    app->init();
    
    std::cout << "test";
    return 0;
}