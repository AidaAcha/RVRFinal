#include <string>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <memory>

#include "Serializable.h"
#include "InputMessage.h"
#include "PositionMessage.h"
#include "Socket.h"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Message: public Serializable
{
public:
    static const size_t MESSAGE_SIZE = sizeof(char) * 88 + sizeof(uint8_t);

    enum MessageType
    {
        LOGIN = 0, CONNNECTED, READYTOPLAY, START, PLAYERPOS, BULLETPOS, INPUT, DEAD, HIT, LOGOUT, CANNONANGLE
    };

    Message(){};
    ~Message();

    Message(const uint8_t typ);
    Message(const uint8_t typ, InputMessage inp, char play);
    Message(const uint8_t typ, PositionMessage b, int bNum);
    Message(const uint8_t typ, PositionMessage p, char play);
    Message(const uint8_t typ, int bNum, char play, int live);

    void to_bin() override;

    int from_bin(char * buff) override;

    uint8_t type;

    char player; 
    int bulletNum;
    int lives;
    
    InputMessage input;
    PositionMessage pos;

};