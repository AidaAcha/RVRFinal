#include "Client.h"

#include "../Utilities/Message.h"
#include "../Utilities/Socket.h"
#include <string>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <memory>

bool Client::startGame = false;

Client::Client(const char * s, const char * p, const char * n) : socket(s, p),
        nick(n){};


void Client::login()
{
    Message msg(Message::LOGIN);
    socket.send(msg, socket); 
}

void Client::logout()
{
    Message msg(Message::LOGOUT);
    socket.send(msg, socket);
}

void Client::net_thread()
{
    while(true)
    {
        // //Recibir Mensajes de red
        Socket* server;
        Message msg;
        int sk = socket.recv(msg, server);
        if(sk ==-1){
            //no se ha mandado ningun mensaje
            continue;
        }

        //START, PLAYERPOS, BULLETPOS, INPUT, DEAD, HIT
        //recibir mensajes
        switch (msg.type)
        {
        case Message::START:
            startGame = true;
            break;
        case Message::PLAYERPOS:
            /* code */
            break;
        case Message::BULLETPOS:
            /* code */
            break;
        case Message::INPUT:
            /* code */
            break;
        case Message::DEAD:
            /* code */
            break;
        case Message::HIT:
            /* code */
            break;
        
        default:
            break;
        }




        // std::cout << ms.nick << ": " << ms.message << '\n';
    }
}
