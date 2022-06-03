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

    if(id < 0 || id >= 2){
        std::cout << "Error, player id is out bounds: "+ id + '\n';
    }



    if(id == '0'){

    Vector2 posTank(400,50);
    
    ClientPlayer* player1 =  new ClientPlayer('0', "./resources/Tank.png", posTank, 32, 32, sdlApp); 
    players.push_back(player1);
    gObjs.push_back(player1);

    posTank = Vector2(400,550);

    ClientPlayer* player2 =  new ClientPlayer('1', "./resources/Tank2.png", posTank, 32, 32, sdlApp);     
    players.push_back(player2);
    gObjs.push_back(player2);
    
    } else {
    Vector2 posTank(400,550);
    
    ClientPlayer* player1 =  new ClientPlayer('1', "./resources/Tank2.png", posTank, 32, 32, sdlApp); 
    players.push_back(player1);
    gObjs.push_back(player1);

    posTank = Vector2(400,50);

    ClientPlayer* player2 =  new ClientPlayer('0', "./resources/Tank.png", posTank, 32, 32, sdlApp);     
    players.push_back(player2);
    gObjs.push_back(player2);
    }
    
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