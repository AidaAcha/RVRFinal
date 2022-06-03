#include "ServerCannon.h"
#include "ServerGame.h"
#include "ServerBullet.h"
#include <math.h>
#include "../Utilities/PositionMessage.h"
#include "../Utilities/Message.h"

ServerCannon::ServerCannon(ServerGame* gam, char c) 
: GameObject()
{
    game_ = gam;
    angle = 0;
    id = c;

}

Vector2 ServerCannon::angleToVector(){
    float angleBueno = angle - 90;
    return Vector2(cos(angleBueno * acos(-1.0) / 180), sin(angleBueno * acos(-1.0) / 180));
}

void ServerCannon::update()
{
    if(cLeft)
    {
        angle = angle - 0.5;
    }
    else if(cRight)
    {
        angle = angle + 0.5;
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

    if(cRight || cLeft)
    sendPositionMessage();

    cRight = false; cLeft = false;
}

void ServerCannon::sendPositionMessage(){
    PositionMessage pMsg;
    pMsg.x = pos.x;
    pMsg.y = pos.y;
    pMsg.angle = angle;
    Message msg(Message::CANNONANGLE, pMsg, id);
    game_->msgToClients(msg);
}