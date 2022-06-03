#include "Wall.h"
#include "../Utilities/GameObject.h"
#include <SDL_image.h>
#include "SDL_App.h"
#include "Vector2.h"

Wall::Wall(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_):
GameObject(pos_, width_, height_) {
    type = Type::Wall_;
    app = app_;
    tex = app->loadTexture(text, width, height);
}; 

void Wall::render(){
    dstRect->x = pos.x;
    dstRect->y = pos.y;
    dstRect->w = width;
    dstRect->h = height;

    SDL_RenderCopyEx(app->getRenderer(), tex, currentFrame, dstRect, angle, NULL, SDL_FLIP_NONE);
}