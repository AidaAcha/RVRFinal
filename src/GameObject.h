#ifndef GameObject_H_
#define GameObject_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Vector2.h"
struct pair
{
    int first;
    int second;

    pair(int f, int s) {first = f; second = s;};
};

class SDL_App;

class GameObject {

public:
    enum Type {Tank, Bullet, Wall};

    
    GameObject(Vector2 _pos, SDL_Texture* _tex, SDL_App* _sdlApp);
    GameObject(SDL_App* _sdlApp) { sdlApp = _sdlApp; };
    virtual ~GameObject() {};
    
    virtual Type getType() {return type; };

    virtual void render();
    virtual void update() = 0;

    float getPosX() { return pos.getX(); };
    float getPosY() { return pos.getY(); };
    SDL_Texture* getTex() { return tex; };
    SDL_Rect getCurrentFrame() { return currentFrame; }

protected:
    Type type;
    SDL_App* sdlApp;
private:
    Vector2 pos;
    //float x, y; //posicion en la ventana (todos los obj lo tienen)
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};

#endif