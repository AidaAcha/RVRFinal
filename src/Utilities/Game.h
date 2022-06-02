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
    Game(SDL_App* _sdlApp) : sdlApp(_sdlApp) {};
    ~Game();

    void init();

    void initGObjs();
    void gameLoop();
    void addGO(GameObject* go);
    void addGOMuro(GameObject* muro);
    std::vector<GameObject*> getObjs() { return gObjs; };
private:
    std::vector<GameObject*> gObjs;
    SDL_App* sdlApp;
    Map* gMapa;
    Tank* player;
    std::vector<GameObject*> murosMap;
};

#endif