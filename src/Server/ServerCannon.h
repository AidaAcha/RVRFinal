#ifndef ServerCannon_H_
#define ServerCannon_H_
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"

class ServerGame;

class ServerCannon : public GameObject
{
public:
    ServerCannon(ServerGame* gam, int idC);
    ~ServerCannon() {};

    void update() override;
    void render() override {};
    void setMessageInput(InputMessage* inp);

    void lookAtDirection(Vector2 dir) override {};
    void setCDirL(bool d) { cLeft = d;};
    void setCDirR(bool d) { cRight = d;};
    void setCShoot(bool d) { cShoot = d;};

    void sendPositionMessage();

    void setPosition(Vector2 p) {pos = p;};

private:

    Vector2 angleToVector();
    void Input();
    void Move();

    ServerGame * game_;
    int id = 0;
    InputMessage* input;

    bool cLeft = false;
    bool cRight = false;
    bool cShoot = false;
};
#endif