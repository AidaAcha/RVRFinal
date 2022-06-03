#include "Input.h"

#include "SDL2/SDL.h"
#include "SDL_quit.h"
#include "SDL_events.h"
#include <iostream>

bool Input::update(){
    
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.key.keysym.sym == SDLK_ESCAPE)
        {
            SDL_Quit();
            return false;
        }

        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_a:
                    inputInfo.left = true;
                    break;
                case SDLK_d:
                    inputInfo.right = true;
                    break;
                case SDLK_w:
                    inputInfo.up = true;
                    break;
                case SDLK_s:
                    inputInfo.down = true;
                    break;
                case SDLK_SPACE:
                    if(event.key.repeat == 0){
                        inputInfo.shoot = true;
                        std::cout << "una vez \n";
                    }
                    else{
                        std::cout << "repe \n";
                        inputInfo.shoot = false;
                     }
                    break;
                case SDLK_LEFT:
                    inputInfo.aimleft = true;
                    break;
                case SDLK_RIGHT:
                    inputInfo.aimright = true;
                    break;
                default:
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_a:
                    inputInfo.left = false;
                    break;
                case SDLK_d:
                    inputInfo.right = false;
                    break;
                case SDLK_w:
                    inputInfo.up = false;
                    break;
                case SDLK_s:
                    inputInfo.down = false;
                    break;
                case SDLK_SPACE:
                    inputInfo.shoot = false;
                    break;
                case SDLK_LEFT:
                    inputInfo.aimleft = false;
                    break;
                case SDLK_RIGHT:
                    inputInfo.aimright = false;
                    break;
                default:
                    break;
                }
                break;
        }
    }
    return true;
}