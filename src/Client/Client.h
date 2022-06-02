#ifndef Client_H_
#define Client_H_

#include "../Utilities/Socket.h"

class Game;

class Client{
public:
    Client(){};
    ~Client(){
        logout();
        if(socket) delete socket;
    }
    /**
     * @param s dirección del servidor
     * @param p puerto del servidor
     */
    void init(const char * s, const char * p, Game* g);

    /**
     *  Envía el mensaje de login al servidor
     */
    void login();

    /**
     *  Envía el mensaje de logout al servidor
     */
    void logout();

    /**
     *  Rutina del thread de Red. Recibe datos de la red.
     */
    void net_thread();

private:

    /**
     * Socket para comunicar con el servidor
     */
    Socket* socket;

    /**
     * Nick del usuario
     */
    std::string nick;

    /**
     * Juego del cliente
     */
    Game* game;
    /**
     * True cuando comienza la partida
     */
    static bool startGame;
    static char id;
};

#endif