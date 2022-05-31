#include "GameObject.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_image.h>
#include "SDL_App.h"
#include "Game.h"

GameObject::GameObject(Vector2 _pos, const char* _tex, int width_, int height_, SDL_App* _sdlApp)
: pos(_pos), sdlApp(_sdlApp), width(width_), height(height_)
{
    int textW; int textH;
    tex = sdlApp->loadTexture(_tex, textW, textH);
    currentFrame = new SDL_Rect();
    currentFrame->x = pos.x;
    currentFrame->y = pos.y;
    currentFrame->w = textW;
    currentFrame->h = textH;

    sdlApp->getGame()->addGO(this);
};

void GameObject::render(){
    SDL_Rect dst;
    dst.x = pos.x;
    dst.y = pos.y;
    dst.w = width;
    dst.h = height;

    SDL_RenderCopy(sdlApp->getRenderer(), tex, currentFrame, &dst);
}

GameObject::~GameObject(){
    SDL_DestroyTexture(tex);
    tex =  nullptr;

    delete currentFrame;
    currentFrame = nullptr;
}