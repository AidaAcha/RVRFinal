#ifndef ServerCannon_H_
#define ServerCannon_H_
#include "../Utilities/GameObject.h"
#include "../Utilities/InputMessage.h"

class ServerCannon : public GameObject
{
public:
    ServerCannon(int idC);
    ~ServerCannon();

    void update();
    void setMessageInput(InputMessage* inp);

private:

    void Input();
    void Move();

    int id = 0;
    InputMessage* input;
};
#endif