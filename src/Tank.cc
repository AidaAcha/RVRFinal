#include "Tank.h"
#include "SDL_App.h"
#include <SDL_image.h>

Tank::Tank(const char* text, int x_, int y_, int size_, SDL_App* app_) : GameObject(app_){
    x = x_; y = y_; size = size_;
    int width; int height;

    texture = sdlApp->loadTexture(text, &width, &height);
    rect = new SDL_Rect{0, 0, width, height};
    type = Type::Tank;
}

void Tank::render(){
    SDL_Rect destRect = {x * size, y * size, size, size};
    SDL_RenderCopy(sdlApp->getRenderer(), texture, rect, &destRect);
}

void Tank::update(){

}

void Tank::setPosition(int x_, int y_){
    x = x_;
    y = y_;
}

Tank::~Tank(){
    SDL_DestroyTexture(texture);
    texture =  nullptr;

    delete rect;
    rect = nullptr;
}