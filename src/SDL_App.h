#ifndef SDLAPP_H_
#define SDLAPP_H_

#include <iostream>
#include <vector>

class SDL_Texture;
class SDL_Renderer;
class GameObject;

class SDL_App {
public:
    SDL_App() {};
    ~SDL_App();

    void init();

    SDL_Texture* loadTexture(const char* text, int& width, int& height);
    void render(GameObject* _go);

    void clearWindow();
    void renderPresent();

    SDL_Renderer* getRenderer() {return renderer;};

    void addGO(GameObject* go);

private:
    SDL_Renderer* renderer;
    void initGObjs();
    void gameLoop();
    std::vector<GameObject*> gObjs;
};

#endif