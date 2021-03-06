#ifndef ClientCannon_H_
#define ClientCannon_H_

#include "../Utilities/GameObject.h"
#include <vector>

class Vector2;
class SDL_Texture;
class SDL_Rect;
class SDL_App;
class Game;
class ClientCannon : public GameObject {
public:
    
    ClientCannon(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_);
    ~ClientCannon();

    void update() override {};
    void render() override;

    void setAngleCannon(double a);

    void setPosition(Vector2 pos_);
    void lookAtDirection(Vector2 dir) override {};
private:
    float speed;
    bool left = false; bool right = false;
    bool shoot = false;

    Game* g;

    double angleCannon = 0;

    SDL_App* sdlApp;
    SDL_Rect* currentFrame;
    SDL_Rect* dstRect;
    SDL_Texture* tex;
};

#endif
