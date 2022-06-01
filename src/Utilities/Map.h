#ifndef Map_H_
#define Map_H_
#include <string>
#include <vector>

class Wall;
class SDL_App;
class Game;

class Map {
public:
    Map(SDL_App* _sdlApp);
    ~Map();

    void LoadMap(const char * path);
    void AddTile(int xpos, int ypos);
    void leer_archivo(const char *nombre);
private:
    std::vector<Wall*> muros;
    SDL_App* sdlApp;
    Game* g;

};

#endif