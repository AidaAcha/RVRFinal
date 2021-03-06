#ifndef ServerCannon_H_
#define ServerCannon_H_
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"

class ServerGame;

class ServerCannon : public GameObject
{
public:
    ServerCannon(ServerGame* gam, char idC);
    ~ServerCannon() {};

    void update() override;
    void render() override {};

    void lookAtDirection(Vector2 dir) override {};
    void setCDirL(bool d) { cLeft = d;};
    void setCDirR(bool d) { cRight = d;};
    void setCShoot(bool d) { cShoot = d;};

    void sendPositionMessage();

    void setPosition(Vector2 p) {pos = p;};

    Vector2 angleToVector();
private:

    void Input();
    void Move();

    ServerGame * game_;
    char id = '0';

    bool cLeft = false;
    bool cRight = false;
    bool cShoot = false;
};
#endif