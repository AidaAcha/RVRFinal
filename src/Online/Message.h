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

/**
 *  Mensaje del protocolo de la aplicación
 *
 *  +-------------------+
 *  | Tipo: uint8_t     | 0 (login), 1 (mensaje), 2 (logout)
 *  +-------------------+
 *  | Nick: char[8]     | Nick incluido el char terminación de cadena '\0'
 *  +-------------------+
 *  |                   |
 *  | Mensaje: char[80] | Mensaje incluido el char terminación de cadena '\0'
 *  |                   |
 *  +-------------------+
 *
 */
class Message: public Serializable
{
public:
    static const size_t MESSAGE_SIZE = sizeof(char) * 88 + sizeof(uint8_t);

    enum MessageType
    {
        LOGIN = 0, START, PLAYERPOS, BULLETPOS, INPUT, DEAD, HIT, LOGOUT
    };

    Message(){};
    ~Message();

    Message(const uint8_t typ);
    Message(const uint8_t typ, InputMessage inp, char play);
    Message(const uint8_t typ, PositionMessage b, int bNum);
    Message(const uint8_t typ, PositionMessage p, char play);

    void to_bin() override;

    int from_bin(char * buff) override;

private:
    uint8_t type;

    char player;
    int bulletNum;
    
    InputMessage input;
    PositionMessage pos;
};