#ifndef Tank_H_
#define Tank_H_

#include "GameObject.h"
#include <vector>

class SDL_Texture;
class SDL_Rect;
class SDL_App;

class Tank : public GameObject {
public:
    
    Tank(const char* text, int x_, int y_, int size_, SDL_App* app_);
    ~Tank();

    void update() override;
    void render() override;

    void setPosition(int x_, int y_);
    pair getPosition() {  return pair(x, y); };

private:
    int x; int y;
    int size;

    SDL_Texture* texture;
    SDL_Rect* rect;
};

#endif
