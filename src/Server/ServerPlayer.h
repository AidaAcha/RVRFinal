#ifndef ServerPlayer_H_
#define ServerPlayer_H_

#include <list>
#include <vector>
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"


class ServerGame;
class Vector2;
class ServerCannon;

class ServerPlayer : public GameObject
{
public:
    ServerPlayer(Vector2 v, ServerGame* gam, char playerID);
    ~ServerPlayer() {};

    void update() override;
    void render() override {}; //not used in server

    void setMessageInput(InputMessage* inp);

    void lookAtDirection(Vector2 dir) override;

    void setPosition(Vector2 pos_);

    void sendPositionMessage();

private:

    void playerHandleInput();
    void Input();
    void Move();
    
    char id = 0; //player id

    ServerGame* _game = nullptr; //reference to game instance

    InputMessage* input;

    float speed;
    Vector2 dir;
    ServerCannon* sc;

    bool cLeft = false; bool cRight = false;
    bool cShoot = false;
};
#endif