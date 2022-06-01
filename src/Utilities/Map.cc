#include "Map.h"
#include "Game.h"
#include "SDL_App.h"
#include <fstream>
#include "Wall.h"

Map::Map(SDL_App* _sdlApp) : sdlApp(_sdlApp){
    if(sdlApp != nullptr)
    {
        g = sdlApp->getGame();
    }
}

Map::~Map(){}

void Map::LoadMap(const char * path)
{
    char c;
    int alto, ancho;
    const char* linea;

    leer_archivo(path);

    AddTile(200,0);
    //AddTile(0,200);
    //AddTile(0,270);
    //AddTile(270,0);
    //AddTile(270, 270);
    //AddTile(200,200);
    //AddTile(270,200);
    //AddTile(200,270);
    //AddTile(340, 270);
    //AddTile(270,340);
    //AddTile(480, 270);

   
}

void Map::AddTile(int xpos, int ypos)
{
    Vector2 pos(xpos, ypos);
    Wall* muro = new Wall("./resources/Wall.png", pos, 70, 70, sdlApp);
    
    if(g!=nullptr) g->addGOMuro(muro);

};

void Map::leer_archivo(const char *nombre){
    
    char aux;
    char aux2[5];
    FILE* f;
    f = fopen(nombre, "r");
    if(f == NULL)
    {
        printf("No se ha podido abrir el fichero. \n");
        exit(1);
    }
    
    while (!feof(f))
    {
        fgets(aux2, 5, f);
        printf("%s", aux2);
    }
    printf("\n");
    fclose(f);

};