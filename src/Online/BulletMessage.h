#ifndef BulletMessage_H_
#define BulletMessage_H_
#include <string>

struct BulletMessage
{
    int x; int y;

    std::string toString()
    {
        return std::to_string(x) + '\0' + std::to_string(y) + '\0';
    }

    void fromString(const char* string)
    {
        int i = 0; std::string aux = "";
        while(string[i] != '\0') {aux += string[i]; i++;}
        
        x = stoi(aux);

        i++; aux = "";
        while(string[i] != '\0') {aux += string[i]; i++;}

        y = stoi(aux);
    }
};

#endif