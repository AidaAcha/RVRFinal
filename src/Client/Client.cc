#include "Client.h"

#include "../Utilities/Message.h"
#include "../Utilities/Socket.h"
#include "Game.h"
#include "../Client/Input.h"
#include "../Utilities/InputMessage.h"
#include "ClientPlayer.h"   

#include <string>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <memory>
#include <thread>

char Client::id = '0';

Client::Client(){
    input = new Input();
}

Client::~Client(){
    logout();
    if(socket) delete socket;
    if(input) delete input;
}


//Initializes client's resources for connection with server
void Client::init(const char * s, const char * p, Game* g)
{
    socket = new Socket(s, p);
    game = g; 

    std::thread([this](){ net_thread();}).detach();

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

void Client::sendReady(){
    Message msg(Message::READYTOPLAY);
    socket->send(msg, *socket);
}

void Client::sendInput(){
    Message msg(Message::INPUT, input->getInputMessage(), id);
    socket->send(msg, *socket);
}

bool Client::getInput(){
    return input->update();
}


void Client::net_thread()
{
    Socket* server = new Socket(*socket);
    while(true)
    {
        // //Recibir Mensajes de red
        Message msg;
        int sk = socket->recv(msg, server);
        if(sk ==-1){
            //no se ha mandado ningun mensaje
            continue;
        }

        //START, PLAYERPOS, BULLETPOS, INPUT, DEAD, HIT
        //recibir mensajes
        switch (msg.type)
        {
        case Message::START:
            std::cout << "Server green lights START game.\n";

            startGame_ = true;
            break;
        case Message::CONNNECTED:
            id = msg.player;
            //init game
            std::cout << "Client connected to server.\n";

            connectedGame_ = true;
            break;
        case Message::PLAYERPOS:{
            ClientPlayer* player = game->getPlayers()[msg.player - '0'];
            player->setPosition(Vector2(msg.pos.x, msg.pos.y));
            player->setAngle(msg.pos.angle);
            break;
        }
        case Message::CANNONANGLE:{
            ClientPlayer* player = game->getPlayers()[msg.player - '0'];
            player->setCannonAngle(msg.pos.angle);
        } break;
        case Message::BULLETPOS:
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
