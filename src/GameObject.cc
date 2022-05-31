#include "GameObject.h"
#include "SDL_App.h"

GameObject::GameObject(Vector2 _pos, const char* _tex, int width_, int height_, SDL_App* _sdlApp)
: pos(_pos), sdlApp(_sdlApp), width(width_), height(height_)
{
    tex = sdlApp->loadTexture(_tex, &width, &height);
    currentFrame = new SDL_Rect();
    currentFrame->x = pos.getX();
    currentFrame->y = pos.getY();
    currentFrame->w = width;
    currentFrame->h = height;

    sdlApp->addGO(this);
};

void GameObject::render(){
    SDL_Rect dst;
    dst.x = pos.getX();
    dst.y = pos.getY();
    dst.w = currentFrame->w;
    dst.h = currentFrame->h;

    SDL_RenderCopy(sdlApp->getRenderer(), tex, currentFrame, &dst);
}

GameObject::~GameObject(){
    SDL_DestroyTexture(tex);
    tex =  nullptr;

    delete currentFrame;
    currentFrame = nullptr;
}