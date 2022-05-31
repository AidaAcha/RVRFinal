#include "Tank.h"
#include "SDL_App.h"
#include <SDL_image.h>

Tank::Tank(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_) : 
    GameObject(pos_, text, width_, height_, app_) {

    type = Type::Tank;
}

void Tank::update(){

}

void Tank::setPosition(Vector2 pos_){
    pos = pos_;
}

Tank::~Tank(){
}