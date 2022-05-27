#ifndef GameObject_H_
#define GameObject_H_

class GameObject {

public:
    enum Type {Tank, Bullet, Wall};

    GameObject() {};
    virtual ~GameObject() {};
    
    virtual Type getType() {return type; };

    virtual void render() = 0;
    virtual void update() = 0;

protected:
    Type type;

};

#endif