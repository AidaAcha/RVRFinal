#include "ServerCannon.h"
#include "ServerGame.h"

ServerCannon::ServerCannon(ServerGame* gam, int c) 
: GameObject()
{
    game_ = gam;
    angle = 0;
    id = c;

}

void ServerCannon::setMessageInput(InputMessage* inp)
{
    input = inp;
}

void ServerCannon::update()
{
    if(cLeft)
    {
        angle = angle - 0.1;
        cLeft = false;
    }
    else if(cRight)
    {
        angle = angle + 0.1;
        cRight = false;
    }
    else if(cShoot)
    {
        cShoot = false;
    }
}