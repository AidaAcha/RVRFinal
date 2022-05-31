#ifndef GameObject_H_
#define GameObject_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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

    GameObject(float _x, float _y, SDL_Texture* _tex, SDL_App* _sdlApp);
    GameObject(SDL_App* _sdlApp) { sdlApp = _sdlApp; };
    virtual ~GameObject() {};
    
    virtual Type getType() {return type; };

    virtual void render();
    virtual void update() = 0;

    float getX() { return x; };
    float getY() { return y; };
    SDL_Texture* getTex() { return tex; };
    SDL_Rect getCurrentFrame() { return currentFrame; }

protected:
    Type type;
    SDL_App* sdlApp;
private:
    float x, y; //posicion en la ventana (todos los obj lo tienen)
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};

#endif