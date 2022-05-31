#include "GameObject.h"
#include "SDL_App.h"

GameObject::GameObject(Vector2 _pos, SDL_Texture* _tex, SDL_App* _sdlApp)
: pos(_pos), tex(_tex), sdlApp(_sdlApp)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
};

void GameObject::render(){

    SDL_Rect dst;
    dst.x = pos.getX();
    dst.y = pos.getY();
    dst.w = currentFrame.w;
    dst.h = currentFrame.h;

    SDL_RenderCopy(sdlApp->getRenderer(), tex, &currentFrame, &dst);
}