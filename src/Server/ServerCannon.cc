#include "ServerCannon.h"
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"
#include "ServerGame.h"

ServerCannon::ServerCannon( ServerGame* gam, int c) 
: game_(gam)
{
    angle = 0;
    id = c;

}


void ServerCannon::setMessageInput(InputMessage* inp)
{
    input = inp;
}

