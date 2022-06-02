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
    client.init("127.0.0.1", "7777", &game);

    bool applicationClosed = false;
    //while(!client.connectedGame());

    game.initGObjs();

    //wait connection

    game.gameLoop();
    
    

    //Deletes

    //Release SDL
        
    std::cout << "Game closed\n";

    return 0;
}