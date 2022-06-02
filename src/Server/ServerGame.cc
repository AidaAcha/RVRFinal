#include "ServerGame.h"
#include "ServerPlayer.h"
#include "Server.h"
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"
#include "../Utilities/PositionMessage.h"
#include "../Utilities/Message.h"

#include "../Utilities/Vector2.h"

#include <iostream>

ServerGame::ServerGame(Server* sv) : server(sv) {}

//Initialize
void ServerGame::init()
{
    initPlayers();
}

//Updates active GameObjects
void ServerGame::update()
{
    for(auto* o : gameObjects)
        o->update();
}

//Creates depending on player 1 or 2
void ServerGame::initPlayers()
{
    players.reserve(2);

    int x = 25; int y = 19;
    
    ServerPlayer* player = new ServerPlayer(Vector2(x,y), this, 0);
    gameObjects.push_back(player);
    players.push_back(player);

    x = 5; y = 19;
    player = new ServerPlayer(Vector2(x,y), this, 1);
    gameObjects.push_back(player);
    players.push_back(player);
}

void ServerGame::setMessageInput(InputMessage* input)
{
    for(int i = 0; i < players.size(); i++)
        players[i]->setMessageInput(&input[i]);
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