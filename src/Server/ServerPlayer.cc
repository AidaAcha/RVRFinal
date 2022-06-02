#include "ServerPlayer.h"
#include "../Utilities/InputMessage.h"
#include "../Utilities/GameObject.h"

ServerPlayer::ServerPlayer(Vector2 v, ServerGame* gam, int playerID)
 : GameObject()
{
    id = playerID;
    _game = gam;
    pos = v;
    angle = 0;
    type = GameObject::Tank_;
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
        angle = 90;
    } else if (input->left)
    {
        angle = -90;
    } else if (input->up) 
    {
        angle = 180;
    }else if (input->down)
    {
        angle = 0;
    }
}

void ServerPlayer::Move()
{
    
}

void ServerPlayer::setMessageInput(InputMessage* inp)
{
    input = inp;
}