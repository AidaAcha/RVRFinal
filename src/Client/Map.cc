#include "Map.h"
#include "../Client/Game.h"
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
    
    fgets(aux2, 5, f);
    //printf("%s", aux2);
    int ancho, alto;
    ancho = atoi(aux2);
    //printf("%i", ancho);
    fgets(aux2, 5, f);
    alto = atoi(aux2);

    for(int i = 0; i < ancho; i++)
    {
        for(int j = 0; j < alto; j++)
        {
            aux = fgetc(f);
            if(aux == 49)
            {
                AddTile(70/2 + j*70,70/2 + i*70);
            }
        }
    }
    printf("\n");
    fclose(f);
};