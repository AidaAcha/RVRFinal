#include "Server.h"

#include "../Utilities/Message.h"

Server::Server(const char * s, const char * p): socket(s, p){
    socket.bind();
    clients.reserve(MAX_PLAYERS);
}

void Server::do_messages(){
    std::cout << "Server up\n" << "Waiting for players\n";

    while(true) //receive messages
    {
        Socket* client;
        Message msg;
        socket.recv(msg, client);

        switch(msg.type)
        {
            case Message::LOGIN:
                if(clients.size() < MAX_PLAYERS) //add player
                {
                    clients.push_back(client);
                    std::cout << "Player " << clients.size() << " joined the game\n";

                    Message ms(Message::CONNNECTED);
                    ms.player = (clients.size() - 1) + '0'; //send id to connected client
                    socket.send(ms, *client);

                }
                else
                {
                    std::cout << "Players full\n";
                }  
            break;

            case Message::LOGOUT:
                for(int i = 0; i < clients.size(); i++) //delete player from saved clients
                {
                    if(*clients[i] == *client)
                    {
                        clients.erase(clients.begin() + i);

                        int id = (msg.player - '0') + 1;
                        std::cout << "Player " << id << " exited game" << std::endl;
                        break;
                    }
                }
            break;
        }
    }
}

void Server::msg_to_clients(Message msg){
    for(Socket* s : clients)
        socket.send(msg, *s);
}