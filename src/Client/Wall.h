#ifndef Wall_H_
#define Wall_H_

#include "../Utilities/GameObject.h"

class Vector2;
class Vector2;
class SDL_Texture;
class SDL_Rect;
class SDL_App;
class Game;


class Wall : public GameObject {
public:
    Wall(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_);
    ~Wall() {};

    void update() override{};
    void render() override;
    void lookAtDirection(Vector2 dir) override {};

    SDL_Texture* getTex() { return tex; };
    SDL_Rect* getCurrentFrame() { return currentFrame; };
    SDL_Rect* getDstRect() {return dstRect;};

private:
    SDL_App* app;
    SDL_Rect* currentFrame;
    SDL_Rect* dstRect;
    SDL_Texture* tex;
};
#endif