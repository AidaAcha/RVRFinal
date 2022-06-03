#ifndef ClientPlayer_H_
#define ClientPlayer_H_

#include "../Utilities/GameObject.h"
#include <vector>
#include "ClientCannon.h"

class Vector2;
class SDL_Texture;
class SDL_Rect;
class SDL_App;
class Game;

class ClientPlayer : public GameObject {
public:
    
    ClientPlayer(char id, const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_);
    ~ClientPlayer();

    void update() override;
    
    void render() override;
    void setPosition(Vector2 pos_);

    void lookAtDirection(Vector2 dir) override {};
    Vector2 getlastPosition() { return lastpos; };

    void setCannonAngle(double a) {cannon->setAngle(a);};

    SDL_Texture* getTex() { return tex; };
    SDL_Rect* getCurrentFrame() { return currentFrame; };
    SDL_Rect* getDstRect() {return dstRect;};

private:
    Vector2 input;
    float speed;
    ClientCannon* cannon;
    Game* g;
    Vector2 lastpos;

    SDL_App* sdlApp;
    SDL_Rect* currentFrame;
    SDL_Rect* dstRect;
    SDL_Texture* tex;
};

#endif
