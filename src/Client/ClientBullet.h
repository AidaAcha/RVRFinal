#ifndef ClientBullet_H_
#define ClientBullet_H_
#include "../Utilities/GameObject.h"

class Vector2;
class SDL_Texture;
class SDL_Rect;
class SDL_App;
class Game;
class ClientPlayer;

class ClientBullet : public GameObject
{
public:
    ClientBullet(Vector2 pos_, const char* tex_, int width_, int height_, SDL_App* app_, int bulletNum);
    ~ClientBullet();
    Type getType() { return type; };
    
    void render();
    void update();
    void lookAtDirection(Vector2 dir) {};
    void setPosition(Vector2 pos_);

    void detectCollision();

    void sendCollisionMsg(ClientPlayer* p);

    SDL_Texture* getTex() { return tex; };
    SDL_Rect* getCurrentFrame() { return currentFrame; };
    SDL_Rect* getDstRect() {return dstRect;};

private:
    Game* g;

    int bulletN = 0;
    char player = '9';

    SDL_App* sdlApp;
    SDL_Rect* currentFrame;
    SDL_Rect* dstRect;
    SDL_Texture* tex;
};

#endif