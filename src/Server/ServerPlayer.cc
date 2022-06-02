#include "ServerPlayer.h"
#include "ServerGame.h"
#include "ServerCannon.h"

ServerPlayer::ServerPlayer(Vector2 v, ServerGame* gam, int playerID)
:  GameObject()
{
    sc = new ServerCannon(gam, playerID);
    id = playerID;
    _game = gam;
    pos = v;
    angle = 0;
    type = GameObject::Tank_;
    dir = Vector2(0,0);
    speed = 1.0;
}

void ServerPlayer::update()
{
    Input();
    Move();

    if(cRight)
    {
        sc->setCDirR(true);
    }
    else if(cLeft)
    {
        sc->setCDirL(true);
    }else if(cShoot)
    {
        sc->setCShoot(true);
    }
}

void ServerPlayer::Input()
{
    if (input->right)
    {
        dir.x += 1;
    } else if (input->left)
    {
        dir.x += -1;
    } else if (input->up)
    {
        dir.y += -1;
    }else if (input->down)
    {
        dir.y += 1;
    }else if(input->aimleft)
    {
        cLeft = true;
        sc->setCDirL(true);

    }else if(input->aimright)
    {
        cRight = true;
        sc->setCDirR(true);
    }else if(input->shoot)
    {
        cShoot = true;
        sc->setCShoot(true);
    }
}

void ServerPlayer::Move()
{
    dir *= speed;
    pos += dir;
}

void ServerPlayer::setMessageInput(InputMessage* inp)
{
    input = inp;
}