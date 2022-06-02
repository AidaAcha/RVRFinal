#include "ServerPlayer.h"
#include "../Utilities/InputMessage.h"
#include "../Utilities/GameObject.h"

ServerPlayer::ServerPlayer(Vector2 v, ServerGame* gam, int playerID)
:  id(playerID)
{
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