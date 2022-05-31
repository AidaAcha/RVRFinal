#ifndef GameObject_H_
#define GameObject_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Vector2.h"

class SDL_App;

class GameObject {

public:
    enum Type {Tank, Bullet, Wall};

    
    GameObject(Vector2 _pos, const char* _tex, int width_, int height_, SDL_App* _sdlApp);
    virtual ~GameObject();
    
    virtual Type getType() {return type; };

    virtual void render();
    virtual void update() = 0;

    float getPosX() { return pos.getX(); };
    float getPosY() { return pos.getY(); };
    SDL_Texture* getTex() { return tex; };
    SDL_Rect* getCurrentFrame() { return currentFrame; }

protected:
    Type type;
    SDL_App* sdlApp;
    Vector2 pos;
    SDL_Rect* currentFrame;
    SDL_Texture* tex;
    int width;
    int height;
};

#endif