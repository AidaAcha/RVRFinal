#include "ClientBullet.h"
#include "SDL_App.h"
#include "../Utilities/GameObject.h"
#include <SDL_image.h>
#include "ClientPlayer.h"
#include "Game.h"
#include "Message.h"

ClientBullet::ClientBullet(Vector2 pos_, const char* tex_, int width_, int height_, SDL_App* app_, int bulletNum) 
: GameObject(), sdlApp(app_), bulletN(bulletNum)
{
    pos = pos_;
    width = width_; height = height_;

    int textW, textH;
    tex = sdlApp->loadTexture(tex_, textW, textH);
    currentFrame = new SDL_Rect();
    dstRect = new SDL_Rect();
    currentFrame->x = 0;
    currentFrame->y = 0;
    currentFrame->w = textW;
    currentFrame->h = textH;

    type = GameObject::Bullet_;

    if(sdlApp != nullptr)
    {
        g = sdlApp->getGame();
    }
}

void ClientBullet::update(){
    detectCollision();
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

void ClientBullet::detectCollision(){
    for(ClientPlayer* p : g->getPlayers()) {
        if(sdlApp->intersectRects(*p->getDstRect(), *getDstRect())){
            player = p->getId();
            p->lives--;
            sendCollisionMsg(p);
        }
    }

    if(sdlApp->outsideMap(pos)){
        player = '9';
        sendCollisionMsg(nullptr);
    }
}

void ClientBullet::sendCollisionMsg(ClientPlayer* p){
    Message msg;
    msg.type = Message::HIT;
    msg.bulletNum = bulletN;
    msg.player = player;

    if(p)
    msg.lives = p->lives;
    else msg.lives = 5;

    g->deleteBullet(bulletN);
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