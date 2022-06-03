#include "Game.h"
#include "Map.h"
#include "SDL_App.h"
#include "SDL_render.h"

#include "../Utilities/GameObject.h"
#include "ClientPlayer.h"

#include "SDL_events.h"
#include "../Utilities/Vector2.h"

// We can add scenes instead of these if it gets bigger
void Game::initGObjs(){
    // const char* tex = "./resources/Tank.png";
    // Vector2 posTank(5,5);
    // player = new Tank(id, tex, posTank, 32, 32, sdlApp);
    // player->setPosition(Vector2(sdlApp->getWindowWidth() / 2, sdlApp->getWindowHeight() / 2));

    if(id < 0 || id >= 2){
        std::cout << "Error, player id is out bounds: "+ id + '\n';
    }

    Vector2 posTank(400,50);

    ClientPlayer* player1 =  new ClientPlayer(id, "./resources/Tank.png", posTank, 32, 32, sdlApp); 
    players.push_back(player1);
    gObjs.push_back(player1);

    posTank = Vector2(400,550);
    
    ClientPlayer* player2 =  new ClientPlayer(id, "./resources/Tank2.png", posTank, 32, 32, sdlApp);     
    players.push_back(player2);
    gObjs.push_back(player2);

    gMapa = new Map(sdlApp);
    gMapa->LoadMap("mapa.txt");
}

void Game::addGO(GameObject* go){
    gObjs.push_back(go);
}

void Game::addGOMuro(GameObject* go){
    murosMap.push_back(go);
}

void Game::renderGObjs(){
    for(int i = 0; i < gObjs.size(); i++)
        gObjs[i]->render();
    sdlApp->renderPresent();
}


Game::~Game(){
    for(int i = 0; i < gObjs.size(); i++)
        delete gObjs[i];
    gObjs.clear();
}