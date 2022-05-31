#include "Game.h"
#include "Map.h"
#include "SDL_App.h"
#include "SDL_render.h"

#include "GameObject.h"
#include "Tank.h"

#include "SDL_events.h"

void Game::init(){
    
    initGObjs();
    gameLoop();
}

// We can add scenes instead of these if it gets bigger
void Game::initGObjs(){
    const char* tex = "./resources/Tank.png";
    Tank* tank = new Tank(tex, Vector2(), 100, 100, sdlApp);
    tank->render();

    //gMapa = new Map(sdlApp);
    //gMapa->LoadMap("mapa.txt");
}

void Game::addGO(GameObject* go){
    gObjs.push_back(go);
}

void Game::gameLoop() {
    bool exit = false;

    while(!exit){
        sdlApp->clearWindow();
        // SDL_Event event;
        // // Handle all Events
        // while (SDL_PollEvent(&event)) { 
        for(auto it = gObjs.cbegin(); it != gObjs.cend(); ++it){
            SDL_Event event;
            while (SDL_PollEvent(&event)) { 
                exit = !(*it)->handleInput(&event);
            }
            (*it)->update();
            (*it)->render();
        }
        sdlApp->renderPresent();
        // }
        // //handle input
    }
};

Game::~Game(){
    for(int i = 0; i < gObjs.size(); i++)
        delete gObjs[i];
    gObjs.clear();
}