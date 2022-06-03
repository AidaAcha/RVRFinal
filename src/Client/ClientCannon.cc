#include "ClientCannon.h"
#include "../Utilities/GameObject.h"
#include "SDL_App.h"
#include <SDL_image.h>
#include <math.h>
#include "Game.h"

ClientCannon::ClientCannon(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_) : 
    GameObject(), sdlApp(app_) {
    
    pos = pos_;
    width = width_; height = height_;

    int textW, textH;
    tex = sdlApp->loadTexture(text, textW, textH);
    currentFrame = new SDL_Rect();
    dstRect = new SDL_Rect();
    currentFrame->x = 0;
    currentFrame->y = 0;
    currentFrame->w = textW;
    currentFrame->h = textH;

    if(sdlApp != nullptr)
    {
        g = sdlApp->getGame();
    }

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
    std::cout << a << "\n";
    angle = a;
}

ClientCannon::~ClientCannon(){
    SDL_DestroyTexture(tex);
    tex =  nullptr;

    delete currentFrame;
    currentFrame = nullptr;

    delete dstRect;
    dstRect = nullptr;

    g = nullptr;
}