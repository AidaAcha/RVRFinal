#ifndef Bullet_H_
#define Bullet_H_

#include "GameObject.h"
#include <vector>
#include <chrono>

class SDL_Texture;
class SDL_Rect;
class SDL_App;

class Bullet : public GameObject {
public:
    
    Bullet(const char* text, Vector2 pos_, int width_, int height_, Vector2 dir_, float speed_, SDL_App* app_);
    ~Bullet();

    void update() override;
    void render() override;
    void lookAtDirection(Vector2 dir) {};

    void setPosition(Vector2 pos_);
private:
    Vector2 dir;
    float speed;
    bool dead = false;
    std::chrono::_V2::system_clock::time_point start;
};

#endif
