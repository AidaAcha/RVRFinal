#include <iostream>
#include "SDL_App.h"
#include "Game.h"

const int WIDTH = 800, HEIGHT = 600;

int main (int argc, char *argv[])
{
    SDL_App* app = new SDL_App();
    app->init();
    app->getGame()->gameLoop();
    return 0;
}