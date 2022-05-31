#include "Map.h"
#include <fstream>
#include "Wall.h"

Map::~Map(){}

void Map::LoadMap(std::string path)
{
    char c;
    int alto, ancho;
    const char* linea;

    AddTile(200,0);
    AddTile(0,200);
    AddTile(0,270);
    AddTile(270,0);
    AddTile(270, 270);
    AddTile(200,200);
    AddTile(270,200);
    AddTile(200,270);
    AddTile(340, 270);
    AddTile(270,340);
    AddTile(480, 270);

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
    Wall* muro = new Wall("./resources/Wall.png", pos, 70, 70, sdlApp);
    //muros->push_back(muro);

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