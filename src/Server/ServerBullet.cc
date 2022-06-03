#include "ServerBullet.h"
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"
#include "../Utilities/PositionMessage.h"
#include "../Utilities/Message.h"
#include "../Client/Game.h"
#include "ServerGame.h"

ServerBullet::ServerBullet(ServerGame* gam, char idB, int numB) 
: GameObject()
{
    game_ = gam;
    angle = 0;
    id = idB;
    bulletNum = numB;
    speed = 1;
}

void ServerBullet::update(){
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;

    sendPositionMessage();
}

void ServerBullet::sendPositionMessage(){
    PositionMessage pMsg;
    pMsg.x = pos.x;
    pMsg.y = pos.y;
    pMsg.angle = angle;
    Message msg(Message::BULLETPOS, pMsg, bulletNum);
    game_->msgToClients(msg);
}


