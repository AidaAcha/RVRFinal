#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>

class SDL_Texture;
class SDL_Renderer;
class GameObject;
class SDL_App;
class Map;
class ClientPlayer;
class ClientBullet;
class Message;

class Game {
public:
    Game(SDL_App* _sdlApp) : sdlApp(_sdlApp), id(-1) {};
    ~Game();

    void initGObjs();
    void addGO(GameObject* go);
    void addGOMuro(GameObject* muro);
    inline std::vector<GameObject*> getObjs() { return gObjs; };
    inline void setID(char id_) {id = id_;};
    inline char getId() {return id;};
    
    void renderGObjs();
    void updateGObjs();

    void renderBackground() {};
    void deleteBullet(int n);

    inline std::vector<ClientPlayer*> getPlayers() { return players; };
    inline std::vector<ClientBullet*> getBullets() { return bullets; };
    inline int getMaxBullets() {return MAX_BULLETS;};
    void tryCreateBullet(Message msg);
private:
    std::vector<GameObject*> gObjs;
    SDL_App* sdlApp;
    Map* gMapa;
    std::vector<ClientPlayer*> players;
    std::vector<ClientBullet*> bullets;
    std::vector<GameObject*> murosMap;
    char id;
    const int MAX_BULLETS = 10;
};

#endif