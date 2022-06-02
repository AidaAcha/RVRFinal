#include "ServerBullet.h"
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"
#include "ServerGame.h"

ServerBullet::ServerBullet(ServerGame* gam, int idB, int numB) 
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
}


