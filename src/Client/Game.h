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
    inline std::vector<ClientPlayer*> getPlayers() { return players; };
private:
    std::vector<GameObject*> gObjs;
    SDL_App* sdlApp;
    Map* gMapa;
    std::vector<ClientPlayer*> players;
    std::vector<GameObject*> murosMap;
    char id;
};

#endif