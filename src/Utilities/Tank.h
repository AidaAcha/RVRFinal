#ifndef Tank_H_
#define Tank_H_

#include "GameObject.h"
#include <vector>
#include "Cannon.h"


class SDL_Texture;
class SDL_Rect;
class SDL_App;
class Game;

class Tank : public GameObject {
public:
    
    Tank(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_);
    ~Tank();

    void update() override;
    bool handleInput(SDL_Event* event) override;

    void setPosition(Vector2 pos_);
    void lookAtDirection(Vector2 dir) override;
    Vector2 getlastPosition() { return lastpos; };
    //void setChocar(bool b) { chocarM = b; };
    

private:
    Vector2 input;
    float speed;
    Cannon* cannon;
    Game* g;
    //bool chocarM = false;
    Vector2 lastpos;
};

#endif
