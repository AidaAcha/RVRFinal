#ifndef GameObject_H_
#define GameObject_H_

#include "Vector2.h"
#include <SDL_events.h>

class SDL_App;
class SDL_Rect;
class SDL_Texture;
// class SDL_Event;

class GameObject {

public:
    enum Type {Tank, Bullet, Wall};

    
    GameObject(Vector2 _pos, const char* _tex, int width_, int height_, SDL_App* _sdlApp);
    virtual ~GameObject();
    
    virtual Type getType() {return type; };

    virtual void render();
    virtual void update() = 0;
    virtual bool handleInput(SDL_Event* event) {return true;};

    float getPosX() { return pos.x; };
    float getPosY() { return pos.y; };
    SDL_Texture* getTex() { return tex; };
    SDL_Rect* getCurrentFrame() { return currentFrame; }

    virtual void lookAtDirection(Vector2 dir) = 0;

protected:
    Type type;
    Vector2 pos;
    
    SDL_App* sdlApp;
    SDL_Rect* currentFrame;
    SDL_Texture* tex;

    int width;
    int height;
    double angle;
};

#endif