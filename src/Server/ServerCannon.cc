#include "ServerCannon.h"
#include "ServerGame.h"
#include "ServerBullet.h"
#include <math.h>
#include "../Utilities/PositionMessage.h"
#include "../Utilities/Message.h"

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

Vector2 ServerCannon::angleToVector(){
    float angleBueno = angle - 90;
    return Vector2(cos(angleBueno * acos(-1.0) / 180), sin(angleBueno * acos(-1.0) / 180));
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
        Vector2 v = angleToVector();
        ServerBullet* bullet = new ServerBullet(game_, id, game_->getBulletCount());
        bullet->setDir(v);
        bullet->setAngle(angle);
        bullet->setPosition(pos);
        cShoot = false;
    }

    sendPositionMessage();
}

void ServerCannon::sendPositionMessage(){
    PositionMessage pMsg;
    pMsg.x = pos.x;
    pMsg.y = pos.y;
    pMsg.angle = angle;
    Message msg(Message::CANNONANGLE, pMsg, id);
    game_->msgToClients(msg);
}