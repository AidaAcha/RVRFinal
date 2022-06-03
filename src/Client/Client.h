#ifndef Client_H_
#define Client_H_

#include "../Utilities/Socket.h"

class Game;
class Input;

class Client{
public:
    Client();
    ~Client();
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

    void sendReady();
    void sendInput();

    bool getInput();

    /**
     *  Rutina del thread de Red. Recibe datos de la red.
     */
    void net_thread();

    inline bool startGame() {return startGame_;};
    inline bool connectedGame() {return connectedGame_;};
    inline char getId() {return id;};

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
     * Manager de input
     */
    Input* input;
    /**
     * True cuando comienza la partida
     */
    bool startGame_ = false;
    bool connectedGame_ = false;
    static char id;
};

#endif