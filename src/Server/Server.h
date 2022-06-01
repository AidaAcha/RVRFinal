#ifndef Server_H_
#define Server_H_

#include <vector>
#include "../Online/Socket.h"

class Message;

class Server 
{
    const int MAX_PLAYERS = 2;
public:
    public:
    /**
     * @param s dirección del servidor
     * @param p puerto del servidor
     **/
    Server(const char * s, const char * p);

    ~Server();

    /**
     *  Thread principal del servidor recive mensajes en el socket y
     *  lo distribuye a los clientes. Mantiene actualizada la lista de clientes
     */
    void do_messages();

    void msg_to_clients(Message msg);

private:

    /**
     *  Lista de clientes conectados al servidor de Chat, representados por
     *  su socket
     */
    std::vector<Socket*> clients;

    /**
     * Socket del servidor
     */
    Socket socket;
};

#endif