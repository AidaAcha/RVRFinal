//CLIENT MAIN

#include <iostream>
#include <time.h>
#include <SDL2/SDL.h>
#include "Client.h"
#include "../Utilities/InputMessage.h"
#include "../Utilities/PositionMessage.h"
#include "SDL_App.h"
#include "Game.h"

int main() 
{
    std::cout << "Initializing...\n";

    //INIT SDL
    SDL_App* app = new SDL_App();
    Game game(app); 
    app->init(&game);
    
    Client client;
    client.init("127.0.0.1", "7778", &game);

    bool applicationClosed = false;


    game.initGObjs();

    //wait connection

    game.gameLoop();
    
    // while(!Client::InitGame() && !applicationClosed) 
    // {    
    //     if(!Platform::Tick()) 
    //         applicationClosed = true;
    // }

    // if(!applicationClosed)
    // {
    //     game.Init(); //initialize GameObjects

    //     std::cout << "Waiting for other players\n";

    //     Client::SendGameReady(); //game is ready 

    //     while(!Client::StartGame() && !applicationClosed) //wait until server is ready
    //     {
    //         if(!Platform::Tick()) 
    //             applicationClosed = true;
    //     }

    //     std::cout << "Start game\n";

    //     //game loop
    //     while(!applicationClosed && Platform::Tick())
    //     {
    //         Input::Tick(); //register input
    
    //         Client::SendInput(Input::GetInputInfo());
    
    //         //Render
    //         Renderer::Clear(0); //clears last frame
    //         game.Render();  //render new frame
    //         Renderer::Present(); //display the new frame buffer  
    //         Platform::Delay(125); 
    //         //Platform::Delay(150);                
    //     }
    // }

    //Deletes

    //Release SDL
        
    std::cout << "Game closed\n";

    return 0;
}