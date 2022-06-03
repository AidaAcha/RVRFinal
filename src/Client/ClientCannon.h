#ifndef ClientCannon_H_
#define ClientCannon_H_

#include "./Utilities/GameObject.h"
#include <vector>

class SDL_Texture;
class SDL_Rect;
class SDL_App;

class ClientCannon : public GameObject {
public:
    
    ClientCannon(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_);
    ~ClientCannon();

    void update() override {};
    void render() override;

    void setAngle(double a);

    void setPosition(Vector2 pos_);
    void lookAtDirection(Vector2 dir) override {};
private:
    float speed;
    bool left = false; bool right = false;
    bool shoot = false;
};

#endif
