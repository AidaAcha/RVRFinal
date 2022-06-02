#include "ServerPlayer.h"
#include "./Utilities/InputMessage.h"
#include "./Utilities/GameObject.h"

ServerPlayer::ServerPlayer(Vector2 v, ServerGame* gam, int playerID)
: pos(v), _game(gam), id(playerID)
{
    angle = 0;
    _type = GameObject::Tank;
}

void ServerPlayer::update()
{
    Input();
    Move();
}

private void ServerPlayer::Input()
{
    if (input.right)
    {
        angle = 90;
    } else if (input.left)
    {
        angle = -90;
    } else if (input.up) 
    {
        angle = 180;
    }else if (inpit.down)
    {
        angle = 0;
    }
}

private void ServerPlayer::Move()
{
    switch (angle)
    {
    case 90:
        pos.x += 1;
        break;
    case -90:
        pos.x += -1;
        break;
    case 180:
        pos.y += -1
        break;
    case 0:
        pos.y += 1;
        break;
    default:
        break;
    }
}

void ServerPlayer::setMessageInput(InputMessage* inp)
{
    input = inp;
}