#ifndef _H_ServerGame_H_
#define _H_ServerGame_H_
#include <vector>

class Server;
class GameObject;
struct BulletMessage; 
struct InputMessage;
class Message;
class ServerPlayer;
class ServerBullet;

class ServerGame 
{
public:
    ServerGame(Server* server);
    ~ServerGame();

    void init();

    void update();

    void setMessageInput(InputMessage* input);

    void msgToClients(Message msg);

    inline bool playerDefeat(){ return endGame; };

    void playerHit();

private: 

    void initPlayers(); //Creates depending if Player 1 || Player 2 
    
    std::vector<GameObject*> gameObjects; //Active GameObjects

    std::vector<ServerPlayer*> players; //Active Players

    std::vector<ServerBullet*> bullets;

    Server* server = nullptr;

    bool endGame = false; //true when a player died
};
#endif