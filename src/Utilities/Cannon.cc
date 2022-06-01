#include "Cannon.h"
#include "SDL_App.h"
#include <SDL_image.h>
#include <math.h>
#include "Game.h"
#include "Bullet.h"

Cannon::Cannon(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_) : 
    GameObject(pos_, text, width_, height_, app_) {

    type = Type::Cannon_;
    speed = 1.0f;
    angle = 0;
}

void Cannon::update(){
    if(left) angle = angle - 0.1;
    else if(right) angle = angle + 0.1;
    else if(shoot){
        Vector2 v = angleToVector();
        Bullet* b = new Bullet("./resources/bala.png", Vector2(0,0), width, height, v, 0.25, sdlApp);
        b->setAngle(angle);
        b->setPosition(Vector2(pos.x, pos.y));
        shoot = false;
    }
}

bool Cannon::handleInput(SDL_Event* event){
    switch ((*event).type)
    {
    case SDL_KEYDOWN:{

        SDL_Keycode k = (*event).key.keysym.sym;
        switch (k)
        {
        case SDLK_LEFT:
            left = true;
            break;
        case SDLK_RIGHT:
            right = true;
            break;
        case SDLK_SPACE:
            shoot = true;
            break;
        default:
            break;
        }
    }
    break;
    case SDL_KEYUP:{

        SDL_Keycode k = (*event).key.keysym.sym;
        switch (k)
        {
        case SDLK_LEFT:
            left = false;
            break;
        case SDLK_RIGHT:
            right = false;
            break;
        case SDLK_SPACE:
            shoot = false;
            break;
        default:
            break;
        }
    }
    default:
        break;
    }
    
    
    return true;
}

void Cannon::render(){
    SDL_Rect dst;
    dst.x = pos.x;
    dst.y = pos.y;
    dst.w = width;
    dst.h = height;

    SDL_Point center = {width/2, height - 5};
    SDL_RenderCopyEx(sdlApp->getRenderer(), tex, currentFrame, &dst, angle, &center, SDL_FLIP_NONE);
}

void Cannon::setPosition(Vector2 pos_){
    pos = pos_;
}

Vector2 Cannon::angleToVector(){
    float angleBueno = angle - 90;
    return Vector2(cos(angleBueno * acos(-1.0) / 180), sin(angleBueno * acos(-1.0) / 180));
}

Cannon::~Cannon(){
}