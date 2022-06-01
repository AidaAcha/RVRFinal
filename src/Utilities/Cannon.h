#ifndef Cannon_H_
#define Cannon_H_

#include "GameObject.h"
#include <vector>

class SDL_Texture;
class SDL_Rect;
class SDL_App;

class Cannon : public GameObject {
public:
    
    Cannon(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_);
    ~Cannon();

    void update() override;
    void render() override;
    bool handleInput(SDL_Event* event) override;

    void setPosition(Vector2 pos_);
    void lookAtDirection(Vector2 dir) override {};
private:

    Vector2 angleToVector();
    float speed;
    bool left = false; bool right = false;
    bool shoot = false;
};

#endif
