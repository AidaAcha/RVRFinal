#include "Client.h"

#include "../Online/Message.h"
#include <string>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <memory>

Client::Client(const char * s, const char * p, const char * n) : socket(s, p),
        nick(n){};


void Client::login()
{
    // std::string msg;

    // Message em(nick, msg);
    // em.type = ChatMessage::LOGIN;

    // socket.send(em, socket);
}

void Client::logout()
{
    // std::string msg;

    // ChatMessage em(nick, msg);
    // em.type = ChatMessage::LOGOUT;

    // socket.send(em, socket);
}

void Client::input_thread()
{
    while (true)
    {
    //     // Leer stdin con std::getline
    //     // Enviar al servidor usando socket
    //     std::string msg;
    //     std::getline(std::cin, msg);

    //     if(msg=="!q"){
    //         logout();
    //         break;
    //     }
    //     else if(msg.length()>80){
    //         std::cerr << "Mensaje excede longitud maxima\n";
    //         continue;
    //     }

    //     ChatMessage em(nick,msg);
    //     em.type = ChatMessage::MESSAGE;

    //     socket.send(em, socket);
    // }
    }
}

void Client::net_thread()
{
    while(true)
    {
        // //Recibir Mensajes de red
        // //Mostrar en pantalla el mensaje de la forma "nick: mensaje"
        // ChatMessage ms;
        // Socket* s;
        // int sk = socket.recv(ms, s);
        // if(sk==-1){
        //     std::cerr << "Error en socket.recv()";
        //     return;
        // }

        // std::cout << ms.nick << ": " << ms.message << '\n';
    }
}
