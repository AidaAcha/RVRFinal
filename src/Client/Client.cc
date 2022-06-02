#include "Client.h"

#include "../Utilities/Message.h"
#include "../Utilities/Socket.h"
#include "../Utilities/Game.h"
#include <string>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <memory>

bool Client::startGame = false;
char Client::id = '0';


//Initializes client's resources for connection with server
void Client::init(const char * s, const char * p, Game* g)
{
    socket = new Socket(s, p);
    game = g;

    //Create thread to receive messages from server
    pthread_t recvThread;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    int res = pthread_create(&recvThread, &attr, &Client::netThread, NULL);

    pthread_attr_destroy(&attr);

    if(res != 0)
        std::cout << "Error, Thread was not created\n";

    login(); //login to server
}


void Client::login()
{
    Message msg(Message::LOGIN);
    socket->send(msg, *socket); 
}

void Client::logout()
{
    Message msg(Message::LOGOUT);
    msg.player = id;
    socket->send(msg, *socket);
}

void* Client::net_thread()
{
    while(true)
    {
        // //Recibir Mensajes de red
        Socket* server;
        Message msg;
        // int sk = socket->recv(msg, server);
        // if(sk ==-1){
        //     //no se ha mandado ningun mensaje
        //     continue;
        // }

        // //START, PLAYERPOS, BULLETPOS, INPUT, DEAD, HIT
        // //recibir mensajes
        // switch (msg.type)
        // {
        // case Message::START:
        //     startGame = true;
        //     break;
        // case Message::CONNNECTED:
        //     id = msg.player;
        //     //init game
        //     break;
        // case Message::PLAYERPOS:
        //     /* code */
        //     break;
        // case Message::BULLETPOS:
        //     /* code */
        //     break;
        // case Message::INPUT:
        //     /* code */
        //     break;
        // case Message::DEAD:
        //     /* code */
        //     break;
        // case Message::HIT:
        //     /* code */
        //     break;
        
        // default:
        //     break;
        // }




        // // std::cout << ms.nick << ": " << ms.message << '\n';
    }
}
