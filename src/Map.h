#ifndef Map_H_
#define Map_H_
#include <string>

class Map {
public:
    Map();
    ~Map();

    void LoadMap(std::string path, int sizeX, int sizeY);
    void AddTile(int srcX, int srcY, int xpos, int ypos);

private:

};

#endif