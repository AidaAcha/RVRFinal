#ifndef Tank_H_
#define Tank_H_

#include "GameObject.h"
#include <vector>

class SDL_Texture;
class SDL_Rect;
class SDL_App;

class Tank : public GameObject {
public:
    
    Tank(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_);
    ~Tank();

    void update() override;
    bool handleInput(SDL_Event* event) override;

    void setPosition(Vector2 pos_);
    void lookAtDirection(Vector2 dir) override;
    
private:
    Vector2 input;
    float speed;
};

#endif
