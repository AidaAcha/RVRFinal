#include "ClientBullet.h"
#include "SDL_App.h"
#include "../Utilities/GameObject.h"
#include <SDL_image.h>

ClientBullet::ClientBullet(Vector2 pos_, const char* tex_, int width_, int height_, SDL_App* app_) 
: GameObject()
{
    pos = pos_;
    width = width_; height = height_;

    int textW, textH;
    tex = sdlApp->loadTexture(tex_, textW, textH);
    currentFrame = new SDL_Rect();
    dstRect = new SDL_Rect();
    currentFrame->x = pos.x;
    currentFrame->y = pos.y;
    currentFrame->w = textW;
    currentFrame->h = textH;

    type = GameObject::Bullet_;

    if(sdlApp != nullptr)
    {
        g = sdlApp->getGame();
    }
}

void ClientBullet::render()
{
    dstRect->x = pos.x;
    dstRect->y = pos.y;
    dstRect->w = width;
    dstRect->h = height;

    SDL_Point center = {width/2, height - 4};
    SDL_RenderCopyEx(sdlApp->getRenderer(), tex, currentFrame, dstRect, angle, &center, SDL_FLIP_NONE);
}

void ClientBullet::setPosition(Vector2 pos_)
{
    pos = pos_;
}

ClientBullet::~ClientBullet()
{
    SDL_DestroyTexture(tex);
    tex =  nullptr;

    delete currentFrame;
    currentFrame = nullptr;

    delete dstRect;
    dstRect = nullptr;

    g = nullptr;
}