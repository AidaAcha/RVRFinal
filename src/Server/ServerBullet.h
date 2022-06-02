#ifndef ServerCannon_H_
#define ServerCannon_H_
#include "../Utilities/GameObject.h"

class ServerGame;

class ServerBullet : public GameObject
{
public:
    ServerBullet(ServerGame* gam, int idB, int numB);
    ~ServerBullet() {};

    void update() override;
    void render() override {};

    void lookAtDirection(Vector2 dir) override {};

private:

    Vector2 dir;
    ServerGame * game_;
    int id = 0;
    int bulletNum = 0;
    int speed;
};
#endif