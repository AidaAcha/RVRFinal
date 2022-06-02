#ifndef ServerPlayer_H_
#define ServerPlayer_H_

#include <list>
#include <vector>
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"

class ServerGame;
class Vector2;

class ServerPlayer : public GameObject
{
public:
    ServerPlayer(Vector2 v, ServerGame* gam, int playerID);
    ~ServerPlayer();

    void update() override;
    void render() override {}; //not used in server

    void setMessageInput(InputMessage* inp);

    void lookAtDirection(Vector2 dir) override {};

private:

    void playerHandleInput();
    void Input();
    void Move();

    void setPosition(Vector2 pos_);
    
    int id = 0; //player id

    ServerGame* _game = nullptr; //reference to game instance

    InputMessage* input;

    float speed;
    Vector2 dir;


};
#endif