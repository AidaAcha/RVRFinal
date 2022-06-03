#ifndef Input_H_
#define Input_H_

#include "../Utilities/InputMessage.h"

class Input{
public:
    Input(){};
    ~Input(){};
    bool update();
    inline InputMessage getInputMessage() {return inputInfo;};
private:
    InputMessage inputInfo;
};

#endif