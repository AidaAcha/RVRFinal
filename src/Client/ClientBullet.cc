#include "ClientBullet.h"
#include "SDL_App.h"
#include "../Utilities/GameObject.h"
#include <SDL_image.h>

ClientBullet::ClientBullet(Vector2 pos_, const char* tex_, int width_, int height_, SDL_App* app_) : 
GameObject(pos_, tex_, width_, height_, app_)
{

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

}