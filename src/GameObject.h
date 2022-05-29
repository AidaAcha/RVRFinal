#ifndef GameObject_H_
#define GameObject_H_

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

    GameObject() {};
    GameObject(SDL_App* _sdlApp) { sdlApp = _sdlApp; };
    virtual ~GameObject() {};
    
    virtual Type getType() {return type; };

    virtual void render() = 0;
    virtual void update() = 0;

protected:
    Type type;
    SDL_App* sdlApp;

};

#endif