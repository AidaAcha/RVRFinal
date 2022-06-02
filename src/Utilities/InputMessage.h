#ifndef InputMessage_H_
#define InputMessage_H_
#include <string>

struct InputMessage
{
    bool right = false; bool left = false;
    bool up = false; bool down = false;
    bool shoot = false;

    std::string toString()
    {
        return std::to_string(right) + std::to_string(left)
            + std::to_string(up) + std::to_string(down) + std::to_string(shoot) + '\0';
    }

    void fromString(const char* string)
    {
        right = (string[0] - '0');
        left = (string[1] - '0');
        up = (string[2] - '0');
        down = (string[3] - '0');
        shoot = (string[4] - '0');
    }
};

#endif