#include "Bullet.h"
#include "SDL_App.h"
#include <SDL_image.h>

Bullet::Bullet(const char* text, Vector2 pos_, int width_, int height_, Vector2 dir_, float speed_, SDL_App* app_) : 
    GameObject(pos_, text, width_, height_, app_) {
    dir = dir_; speed = speed_;
    type = Type::Bullet_;
}

void Bullet::update(){
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;
}

void Bullet::render(){
    SDL_Rect dst;
    dst.x = pos.x;
    dst.y = pos.y;
    dst.w = width;
    dst.h = height;

    SDL_Point center = {width/2, height - 4};
    SDL_RenderCopyEx(sdlApp->getRenderer(), tex, currentFrame, &dst, angle, &center, SDL_FLIP_NONE);
}

void Bullet::setPosition(Vector2 pos_){
    pos = pos_;
}

Bullet::~Bullet(){
}