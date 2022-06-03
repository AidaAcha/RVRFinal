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
    InputMessage* getMessageInput() {return input;};

    void lookAtDirection(Vector2 dir) override;

    void setPosition(Vector2 pos_);

    void sendPositionMessage();

    ServerCannon* getCannon() {return sc;};
    void setLives(int l) {lives = l;};

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

    int lives;

    const int MAX_LIVES = 5;
};
#endif