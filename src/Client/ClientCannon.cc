#include "ClientCannon.h"
#include "SDL_App.h"
#include <SDL_image.h>
#include <math.h>
#include "Game.h"

ClientCannon::ClientCannon(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_) : 
    GameObject(pos_, text, width_, height_, app_) {

    type = Type::Cannon_;
    speed = 1.0f;
    angle = 0;
}

void ClientCannon::render(){
    dstRect->x = pos.x;
    dstRect->y = pos.y;
    dstRect->w = width;
    dstRect->h = height;

    SDL_Point center = {width/2, height - 5};
    SDL_RenderCopyEx(sdlApp->getRenderer(), tex, currentFrame, dstRect, angle, &center, SDL_FLIP_NONE);
}

void ClientCannon::setPosition(Vector2 pos_){
    pos = pos_;
}

void ClientCannon::setAngle(double a){
    angle = a;
}

ClientCannon::~ClientCannon(){
}