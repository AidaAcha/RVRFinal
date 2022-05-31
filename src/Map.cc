#include "Map.h"
#include <fstream>
#include "Wall.h"

Map::~Map(){}

void Map::LoadMap(std::string path)
{
    char c;
    int alto, ancho;
    const char* linea;

    AddTile(2,2);
    AddTile(3,2);
    AddTile(2,3);
    AddTile(3,3);
    /*std::fstream mapFile;
    mapFile.open(path);

    getline(mapFile, linea);
    alto = std::stoi(linea);

    getline(mapFile, linea);
    ancho = std::stoi(linea);

    for(int y = 0; y < alto - 1; y++){
        getline(mapFile, linea);
        for(int x = 0; x < linea.length() - 1; x++){
            if(linea[x] == 1){
                AddTile(x,y);
            }
        }
    }

    mapFile.close();*/
}

void Map::AddTile(int xpos, int ypos)
{
    Vector2 pos(xpos, ypos);
    Wall* muro = new Wall("./resources/Wall.png", pos, 32, 32, sdlApp);
    muros->push_back(muro);

};

/*void leer_archivo(char *nombre){
    char temp[50];
    int cont = 0;
    FILE *archivo;
    archivo = fopen(nombre, "r");
    if(archivo){
        
        while (!feof(archivo))
        {
            fgets(temp, 50, archivo);
            cont++;
        }
        

    }else{
        fprintf(stderr, "No se puede abrir el archivo %s para lectura\n");
        exit(1);
    }
}*/