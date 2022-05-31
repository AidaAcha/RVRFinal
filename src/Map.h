#ifndef Map_H_
#define Map_H_
#include <string>
#include <vector>

class Wall;
class SDL_App;
class Map {
public:
    Map(SDL_App* _sdlApp) : sdlApp(_sdlApp) {};
    ~Map();

    void LoadMap(std::string path);
    void AddTile(int xpos, int ypos);

private:
    std::vector<Wall*>* muros;
    SDL_App* sdlApp;
};

#endif