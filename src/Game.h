#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>

class SDL_Texture;
class SDL_Renderer;
class GameObject;
class SDL_App;
class Map;

class Game {
public:
    Game(SDL_App* _sdlApp) : sdlApp(_sdlApp) {};
    ~Game();

    void init();

    void gameLoop();
    void addGO(GameObject* go);
private:
    void initGObjs();
    std::vector<GameObject*> gObjs;
    SDL_App* sdlApp;
    //Map* gMapa;
};

#endif