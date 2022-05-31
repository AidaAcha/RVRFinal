#include "Bullet.h"
#include "SDL_App.h"
#include <SDL_image.h>

Bullet::Bullet(const char* text, Vector2 pos_, int width_, int height_, Vector2 dir_, float speed_, SDL_App* app_) : 
    GameObject(pos_, text, width_, height_, app_) {
    dir = dir_; speed = speed_;
    type = Type::Bullet;
}

void Bullet::update(){
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;
}

void Bullet::setPosition(Vector2 pos_){
    pos = pos_;
}

Bullet::~Bullet(){
}