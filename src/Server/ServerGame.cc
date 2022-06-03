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
            bullets.push_back(sb);
            gameObjects.push_back(sb);
            std::cout << "nueva bala server \n";
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

//Relocates fruit once eaten, chooses new fruit location
void ServerGame::playerHit()
{}

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