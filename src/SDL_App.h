#ifndef SDLAPP_H_
#define SDLAPP_H_

#include <iostream>
#include <vector>

class SDL_Texture;
class SDL_Renderer;
class GameObject;
class Game;

class SDL_App {
public:
    SDL_App() {};
    ~SDL_App();

    void init();

    SDL_Texture* loadTexture(const char* text, int& width, int& height);

    void clearWindow();
    void renderPresent();

    SDL_Renderer* getRenderer() {return renderer;};
    Game* getGame() {return game;};

    bool intersectRects(SDL_Rect& rect1, SDL_Rect& rect2);
    bool insideRect(Vector2& pos, SDL_Rect& rect);

private:
    SDL_Renderer* renderer;
    Game* game;
};

#endif