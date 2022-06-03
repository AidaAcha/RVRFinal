#include "Game.h"
#include "Map.h"
#include "SDL_App.h"
#include "SDL_render.h"

#include "../Utilities/GameObject.h"
#include "ClientPlayer.h"

#include "SDL_events.h"
#include "../Utilities/Vector2.h"

#include "../Utilities/Message.h"
#include "../Utilities/PositionMessage.h"
#include "ClientBullet.h"

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
    
   for (int i = 0; i < MAX_BULLETS; ++i){
        bullets.push_back(nullptr);
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

void Game::updateGObjs(){
    for(int i = 0; i < gObjs.size(); i++)
        gObjs[i]->update();
}

void Game::deleteBullet(int n){
    for(int i = 0; i < gObjs.size(); i++){
        if(gObjs[i] == bullets[n]){
            gObjs.erase(gObjs.begin() + i);
            break;
        }
    }
    bullets[n] = nullptr;
}

void Game::tryCreateBullet(Message msg){
    if(msg.bulletNum >= 0 && msg.bulletNum < MAX_BULLETS){
         if(!bullets[msg.bulletNum]){
            bullets[msg.bulletNum] = new ClientBullet(
                Vector2(msg.pos.x, msg.pos.y), "./resources/bala.png", 50,50, sdlApp, msg.bulletNum
            );
                bullets.push_back(bullets[msg.bulletNum]);
                gObjs.push_back(bullets[msg.bulletNum]);
         }
         else{
            bullets[msg.bulletNum]->setPosition(Vector2(msg.pos.x, msg.pos.y));
         }
         bullets[msg.bulletNum]->setAngle(msg.pos.angle);
        
    }    
}

Game::~Game(){
    for(int i = 0; i < gObjs.size(); i++)
        delete gObjs[i];
    gObjs.clear();
}