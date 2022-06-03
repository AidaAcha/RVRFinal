#ifndef ServerBullet_H_
#define ServerBullet_H_
#include "../Utilities/GameObject.h"

class ServerGame;

class ServerBullet : public GameObject
{
public:
    ServerBullet(ServerGame* gam, char idB, int numB);
    ~ServerBullet() {};

    void update() override;
    void render() override {};

    void lookAtDirection(Vector2 dir) override {};

    void setDir(Vector2 d) {dir = d;};

    void setPosition(Vector2 p) {pos = p;};

    void sendPositionMessage();

private:

    Vector2 dir;
    ServerGame* game_;
    int id = 0;
    int bulletNum = 0;
    int speed;
};
#endif