#ifndef Vector2_H_
#define Vector2_H_

#include <iostream>

class Vector2
{
public:
    Vector2():x(0.0f), y(0.0f){};
    Vector2(float _x, float _y): x(_x), y(_y) {};

    void print(){
        std::cout << x << ", " << y << "\n";
    }

    float getX() { return x; };
    float getY() { return y; };

    void setX(float _x) { x = _x; }
    void setY(float _y) { y = _y; }
private:
    float x, y;
};

#endif