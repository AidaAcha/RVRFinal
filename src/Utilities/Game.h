#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>

class SDL_Texture;
class SDL_Renderer;
class GameObject;
class SDL_App;
class Map;
class Tank;

class Game {
public:
    Game(SDL_App* _sdlApp) : sdlApp(_sdlApp), id(-1) {};
    ~Game();

    void init();

    void initGObjs();
    void gameLoop();
    void addGO(GameObject* go);
    void addGOMuro(GameObject* muro);
    inline std::vector<GameObject*> getObjs() { return gObjs; };
    inline void setID(char id_) {id = id_;};
    inline char getId() {return id;};
private:
    std::vector<GameObject*> gObjs;
    SDL_App* sdlApp;
    Map* gMapa;
    Tank* player;
    std::vector<GameObject*> murosMap;
    char id;
};

#endif