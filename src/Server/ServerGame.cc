#include "ServerGame.h"
#include "ServerPlayer.h"
#include "Server.h"
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"
#include "../Utilities/PositionMessage.h"
#include "../Utilities/Message.h"
#include "ServerBullet.h"

#include "../Utilities/Vector2.h"
#include "ServerCannon.h"
#include <chrono>

#include <iostream>

ServerGame::ServerGame(Server* sv) : server(sv) {}

//Initialize
void ServerGame::init()
{
    initPlayers();
    start = std::chrono::high_resolution_clock::now();

    // for(int i = 0; i < 10; i++)
    //     bullets.push_back(nullptr);
}

void ServerGame::checkBullets(){
    for(int i = 0; i < 2; i++){
        if(players[i]->getMessageInput()->shoot && bullets.size() < MAX_BULLETS){
            players[i]->getMessageInput()->shoot = false;

            auto time_passed = std::chrono::high_resolution_clock::now() - start;
            using namespace std::chrono_literals;
            if(time_passed < 1s) continue;
            start = std::chrono::high_resolution_clock::now();
            
            ServerBullet* sb = new ServerBullet(this, i, bullets.size());
            sb->setPosition(players[i]->getPosition());
            double angle = players[i]->getCannon()->getAngle();
            sb->setAngle(angle);
            sb->setDir(players[i]->getCannon()->angleToVector());

            // int j = 0;
            // while(j < 10 && bullets[j]) j++;
            // if(j == 10) return;
            // bullets[j] = sb;

            bullets.push_back(sb);

            gameObjects.push_back(sb);
            std::cout << "new bullet \n";
        }
    }
}

//Updates active GameObjects
void ServerGame::update()
{
    checkBullets();
    for(auto* o : gameObjects)
        o->update();
}

//Creates depending on player 1 or 2
void ServerGame::initPlayers()
{
    players.reserve(2);

    Vector2 posTank = Vector2(400,50);
    
    ServerPlayer* player = new ServerPlayer(posTank, this, '0');
    gameObjects.push_back(player);
    players.push_back(player);

    posTank = Vector2(400,550);

    player = new ServerPlayer(posTank, this, '1');
    gameObjects.push_back(player);
    players.push_back(player);
}

void ServerGame::setMessageInput(InputMessage* input)
{
    for(int i = 0; i < players.size(); i++)
        players[i]->setMessageInput(&input[i]);
} 

void ServerGame::addGO(GameObject* go){
    gameObjects.push_back(go);
}

void ServerGame::playerHit(Message msg){
    players[(msg.player - '0')]->setLives(msg.lives);

    if(msg.player == '0') std::cout << "Player 0 lives: " + msg.lives + '\n';
    else if (msg.player == '1') std::cout << "Player 1 lives: " + msg.lives + '\n';

    for(int i = 0; i < gameObjects.size(); i++){
        if(gameObjects[i] == bullets[msg.bulletNum]){
            gameObjects.erase(gameObjects.begin() + i);
            break;
        }
    }
    bullets[msg.bulletNum] = nullptr;


    if(msg.player > 0 && msg.player < 2){
        if(msg.lives <= 0) {
        //send win/lose
        }
        else{

        }
    }

}

void ServerGame::msgToClients(Message msg){
    server->msg_to_clients(msg);
}

ServerGame::~ServerGame()
{
    //delete GameObjects allocated memory
    for (auto o : gameObjects)
        delete o;

    gameObjects.clear();
    players.clear();
    bullets.clear();
}