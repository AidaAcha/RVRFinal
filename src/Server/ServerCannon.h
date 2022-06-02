#ifndef ServerCannon_H_
#define ServerCannon_H_S
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"

class ServerGame;

class ServerCannon : public GameObject
{
public:
    ServerCannon(ServerGame* gam, int idC);
    ~ServerCannon();

    void update();
    void setMessageInput(InputMessage* inp);

private:

    void Input();
    void Move();

    ServerGame * game_;
    int id = 0;
    InputMessage* input;


};
#endif