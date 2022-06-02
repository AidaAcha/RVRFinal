#ifndef ServerCannon_H_
#define ServerCannon_H_
#include "./Utilities/GameObject.h"
#include "./Utilities/InputMessage.h"

class ServerCannon : public GameObject
{
public:
    ServerCannon();
    ~ServerCannon();

    void update();
    void setMessageInput(InputMessage* inp);

private:

    InputMessage* input;
};
#endif