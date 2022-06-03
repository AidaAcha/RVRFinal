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

    sc->setPosition(Vector2(pos.x, pos.y - height / 3));

    angle = 0;
    type = GameObject::Tank_;
    dir = Vector2(0,0);
    speed = 1.0;
}

void ServerPlayer::setPosition(Vector2 p) {pos = p;};

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
    lookAtDirection(dir);

    dir *= speed;
    pos += dir;

    dir.clear();
}

void ServerPlayer::lookAtDirection(Vector2 dir){
    if(dir == Vector2(1,0))
        angle = 90;
    else if(dir == Vector2(-1,0))
        angle = -90;
    else if(dir == Vector2(0,1))
        angle = 180;
    else if(dir == Vector2(0,-1))
        angle = 0;
}

void ServerPlayer::setMessageInput(InputMessage* inp)
{
    input = inp;
}