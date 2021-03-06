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
    void clear() {x = 0; y = 0;};
    float x, y;

    Vector2& operator+=(const Vector2& other){

      this->x += other.x;
      this->y+= other.y;
      return *this;
    }

    Vector2& operator*=(const float& other){

      this->x *= other;
      this->y *= other;
      return *this;
    }

    Vector2& operator-=(const Vector2& other){

      this->x -= other.x;
      this->y -= other.y;
      return *this;
    }

    bool operator==(const Vector2& other){
      return this->x == other.x && this->y == other.y;
    }
};

#endif