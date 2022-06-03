#ifndef ClientBullet_H_
#define ClientBullet_H_
#include "../Utilities/GameObject.h"

class Vector2;
class ClientBullet : public GameObject
{
public:
    ClientBullet(Vector2 pos_, const char* tex_, int width_, int height_, SDL_App* app_);
    ~ClientBullet();
    Type getType() { return type; };
    void render();
    void update() {};
    void lookAtDirection() {};
    void setPosition(Vector2 pos_);

    SDL_Texture* getTex() { return tex; };
    SDL_Rect* getCurrentFrame() { return currentFrame; };
    SDL_Rect* getDstRect() {return dstRect;};

private:
    Game* g;

    SDL_App* sdlApp;
    SDL_Rect* currentFrame;
    SDL_Rect* dstRect;
    SDL_Texture* tex;
};

#endif