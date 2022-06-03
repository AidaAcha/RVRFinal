#ifndef Wall_H_
#define Wall_H_

#include "../Utilities/GameObject.h"

class Wall : public GameObject {
public:
    Wall(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_);
    ~Wall() {};

    void update() override{};
    void lookAtDirection(Vector2 dir) override {};
};
#endif