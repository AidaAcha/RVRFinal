#ifndef PositionMessage_H_
#define PositionMessage_H_
#include <string>

struct PositionMessage
{
    int x; int y; double angle;

    std::string toString()
    {
        return std::to_string(x) + '\0' + std::to_string(y) + '\0' + std::to_string(angle) + '\0';
    }

    void fromString(const char* string)
    {
        int i = 0; std::string aux = "";
        while(string[i] != '\0') {aux += string[i]; i++;}
        
        x = stoi(aux);

        i++; aux = "";
        while(string[i] != '\0') {aux += string[i]; i++;}

        y = stoi(aux);

        i++; aux = "";
        while(string[i] != '\0') {aux += string[i]; i++;}

        angle = stod(aux);
    }
};

#endif