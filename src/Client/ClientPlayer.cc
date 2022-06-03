#include "ClientPlayer.h"
#include "../Utilities/GameObject.h"
#include "SDL_App.h"
#include <SDL_image.h>
#include "ClientCannon.h"
#include "Game.h"

ClientPlayer::ClientPlayer(char id, const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_) : 
    GameObject(), lastpos(pos_), sdlApp(app_) 
    {
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
    
    id == '0' ?
        cannon = new ClientCannon("./resources/Canon.png", Vector2(0,0), width_, height_, app_)
        : cannon = new ClientCannon("./resources/Canon2.png", Vector2(0,0), width_, height_, app_);

    type = Type::Tank_;
    speed = 1.0f;

    cannon->setPosition(Vector2(pos.x, pos.y - height / 3));

    if(sdlApp != nullptr)
    {
        g = sdlApp->getGame();
    }

    g->addGO(cannon);
}

void ClientPlayer::update(){}

void ClientPlayer::render()
{
    dstRect->x = pos.x;
    dstRect->y = pos.y;
    dstRect->w = width;
    dstRect->h = height;

    SDL_RenderCopyEx(sdlApp->getRenderer(), tex, currentFrame, dstRect, angle, NULL, SDL_FLIP_NONE);
    cannon->render();
}

void ClientPlayer::setPosition(Vector2 pos_){
    pos = pos_;
    cannon->setPosition(Vector2(pos.x, pos.y - height / 3));
}

ClientPlayer::~ClientPlayer(){
    SDL_DestroyTexture(tex);
    tex =  nullptr;

    delete currentFrame;
    currentFrame = nullptr;

    delete dstRect;
    dstRect = nullptr;

    g = nullptr;
}