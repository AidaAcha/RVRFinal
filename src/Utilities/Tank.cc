#include "Tank.h"
#include "SDL_App.h"
#include <SDL_image.h>
#include "Cannon.h"
#include "Game.h"

Tank::Tank(const char* text, Vector2 pos_, int width_, int height_, SDL_App* app_) : 
    GameObject(pos_, text, width_, height_, app_), lastpos(pos_) {
    ;
    cannon = new Cannon("./resources/Canon.png", Vector2(0,0), width_, height_, app_);

    type = Type::Tank_;
    speed = 1.0f;
    if(sdlApp != nullptr)
    {
        g = sdlApp->getGame();
    }
}

void Tank::update(){
    
    //uso input
    input.x *= speed;
    input.y *= speed;
    lastpos = pos;
    pos += input;
    
    Vector2 cannonPos = Vector2(pos.x, pos.y - height/3);
    cannon->setPosition(cannonPos);

    lookAtDirection(input);

    //borro input
    input.clear();
}

bool Tank::handleInput(SDL_Event* event){
    switch ((*event).type)
    {
    case SDL_KEYDOWN:{

        SDL_Keycode k = (*event).key.keysym.sym;
        switch (k)
        {
        case SDLK_a:
            input.x += -1;
            break;
        case SDLK_d:
            input.x += 1;
            break;
        case SDLK_w:
            input.y += -1;
            break;
        case SDLK_s:
            input.y += 1;
            break;
        case SDLK_ESCAPE:
            return false;
        default:
            break;
        }
    }
    break;
    default:
        break;
    }
    
    
    return true;
}

void Tank::setPosition(Vector2 pos_){
    pos = pos_;
}

void Tank::lookAtDirection(Vector2 dir){
    if(dir == Vector2(1,0))
        angle = 90;
    else if(dir == Vector2(-1,0))
        angle = -90;
    else if(dir == Vector2(0,1))
        angle = 180;
    else if(dir == Vector2(0,-1))
        angle = 0;
}

Tank::~Tank(){
}