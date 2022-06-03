#include "Wall.h"
#include "../Utilities/GameObject.h"
#include <SDL_image.h>
#include "Vector2.h"

Wall::Wall(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_):
GameObject(pos_, text, width_, height_, app_){
    type = Type::Wall_;
};