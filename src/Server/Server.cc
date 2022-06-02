#include "Server.h"

#include "../Utilities/Message.h"
#include "ServerGame.h"

bool Server::allInputReceived = false;
bool Server::endGame = false;
InputMessage* Server::inputPlayers = nullptr;
ServerGame* Server::game = nullptr;

Server::Server(const char * s, const char * p) {
    socket = new Socket(s, p);
    socket->bind();
    clients.reserve(MAX_PLAYERS);
    inputPlayers = new InputMessage[MAX_PLAYERS];
}

void Server::do_messages(){
    std::cout << "Server up\n" << "Waiting for players\n";

    int numPlayers = 0;
    int numInputPlayers = 0;
    while(true) //receive messages
    {
        Socket* client;
        Message msg;
        socket->recv(msg, client);
        std::cout << "LLEGA NUEVO MENSAJE...\n";

        switch(msg.type)
        {
            case Message::LOGIN:
                if(clients.size() < MAX_PLAYERS) //add player
                {
                    clients.push_back(client);
                    std::cout << "Player " << clients.size() << " joined the game\n";

                    Message ms(Message::CONNNECTED);
                    ms.player = (clients.size() - 1) + '0'; //send id to connected client
                    socket->send(ms, *client);

                    if(endGame)
                        endGame = false;
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
                        std::cout << "Player " << id << " exited game" << "\n";
                        break;
                    }
                }

                numInputPlayers = 0;
                endGame = true;
                numPlayers = 0;
            break;

            case Message::READYTOPLAY: {
                numPlayers++;
                if(numPlayers >= MAX_PLAYERS){
                    
                    msg_to_clients(Message(Message::START));
                    std::cout << "WarTanks ready to play" << "\n";
                }
            } break;

            case Message::INPUT: {
                numInputPlayers++;
                inputPlayers[(msg.player - '0')] = InputMessage(msg.input);

                if(numInputPlayers >= MAX_PLAYERS){
                    numInputPlayers = 0;
                    allInputReceived = true;
                }
            }
        }
    }
}

void Server::msg_to_clients(Message msg){
    for(Socket* s : clients)
        socket->send(msg, *s);
}

void Server::createThreadGame(){
    pthread_t game_t;
    pthread_attr_t game_attr;

    game = new ServerGame(this);
    game->init();

    pthread_attr_init(&game_attr);
    pthread_attr_setdetachstate(&game_attr, PTHREAD_CREATE_DETACHED);
    
    int result = pthread_create(&game_t, &game_attr, PlayGame, NULL);
}

void* Server::PlayGame(void*){
    while(!endGame && game->playerDefeat())
        if(allInputReceived){
            game->setMessageInput(inputPlayers);
            game->update();
            allInputReceived = false;
        }
    pthread_exit(NULL);
}

Server::~Server(){
    delete socket;
    socket = nullptr;

    delete[] inputPlayers;
}