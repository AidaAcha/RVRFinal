#include "GameObject.h"
#include "../Client/Game.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_image.h>
#include "SDL_App.h"

GameObject::GameObject(Vector2 _pos, const char* _tex, int width_, int height_, SDL_App* _sdlApp)
: pos(_pos), sdlApp(_sdlApp), width(width_), height(height_)
{
    int textW; int textH;
    tex = sdlApp->loadTexture(_tex, textW, textH);
    currentFrame = new SDL_Rect();
    dstRect = new SDL_Rect();
    currentFrame->x = pos.x;
    currentFrame->y = pos.y;
    currentFrame->w = textW;
    currentFrame->h = textH;
    angle = 0;

    sdlApp->getGame()->addGO(this);
};

void GameObject::render(){
    dstRect->x = pos.x;
    dstRect->y = pos.y;
    dstRect->w = width;
    dstRect->h = height;

    SDL_RenderCopyEx(sdlApp->getRenderer(), tex, currentFrame, dstRect, angle, NULL, SDL_FLIP_NONE);
}

GameObject::~GameObject(){
    SDL_DestroyTexture(tex);
    tex =  nullptr;

    delete currentFrame;
    currentFrame = nullptr;
}