#ifndef GameObject_H_
#define GameObject_H_

#include "Vector2.h"

class GameObject {

public:
    enum Type {Tank_, Cannon_, Bullet_, Wall_};

    GameObject(){};
    GameObject(Vector2 pos_, int width_, int height_) : pos(pos_), width(width_), height(height_) {};
    virtual ~GameObject() {};
    
    virtual Type getType() {return type; };

    virtual void render() = 0;
    virtual void update() = 0;

    float getPosX() { return pos.x; };
    float getPosY() { return pos.y; };

    Vector2 getPosition() { return pos; };

    virtual void lookAtDirection(Vector2 dir) = 0;
    
    void setAngle(float a) {angle = a;};
    double getAngle() {return angle;};

protected:
    Type type;
    Vector2 pos;

    int width;
    int height;
    double angle = 0;
};

#endif