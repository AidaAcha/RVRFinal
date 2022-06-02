#include "Bullet.h"
#include "SDL_App.h"
#include <SDL_image.h>

Bullet::Bullet(const char* text, Vector2 pos_, int width_, int height_, Vector2 dir_, float speed_, SDL_App* app_) : 
    GameObject(pos_, text, width_, height_, app_) {
    dir = dir_; speed = speed_;
    type = Type::Bullet_;
    start = std::chrono::high_resolution_clock::now();
}

void Bullet::update(){
    using namespace std::chrono_literals;
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;

    auto time_passed = std::chrono::high_resolution_clock::now() - start;
    if(time_passed > 1s) dead = true;
}

void Bullet::render(){
    dstRect->x = pos.x;
    dstRect->y = pos.y;
    dstRect->w = width;
    dstRect->h = height;

    SDL_Point center = {width/2, height - 4};
    SDL_RenderCopyEx(sdlApp->getRenderer(), tex, currentFrame, dstRect, angle, &center, SDL_FLIP_NONE);
}

void Bullet::setPosition(Vector2 pos_){
    pos = pos_;
}

Bullet::~Bullet(){
}