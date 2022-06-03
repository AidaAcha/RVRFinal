#include "Message.h"
#include <string>
#include <iostream>

Message::~Message(){
    if(_data){ delete[] _data; _data = nullptr; }
}

Message::Message(const uint8_t typ) : type(typ) {}
Message::Message(const uint8_t typ, InputMessage inp, char play) : type(typ), input(inp), player(play) {}
Message::Message(const uint8_t typ, PositionMessage b, int bNum) : type(typ), bulletNum(bNum), pos(b) {}
Message::Message(const uint8_t typ, PositionMessage p, char play) : type(typ), player(play), pos(p) {}
Message::Message(const uint8_t typ, int bNum, char play) : type(typ), player(play), bulletNum(bNum) {}

void Message::to_bin(){
    switch (type)
    {
    case LOGIN:
    case START: {
        alloc_data(sizeof(uint8_t));
        memcpy((void*) _data, (void*) &type, sizeof(uint8_t));
    }
        break;
    case INPUT: {
        alloc_data(sizeof(uint8_t) + sizeof(char) * (sizeof(InputMessage) + 1));
        char* aux = _data;

        memcpy((void*) aux, (void*)&type, sizeof(uint8_t));
        aux += sizeof(uint8_t);
        
        memcpy((void*) aux, &player, sizeof(char));
        aux += sizeof(char);

        memcpy((void*) aux, input.toString().c_str(), sizeof(char) * (sizeof(InputMessage) + 1));
    } break;
    case DEAD:
    case LOGOUT:
    case READYTOPLAY:
    case CONNNECTED: {
        alloc_data(sizeof(uint8_t) + sizeof(char));
        char* aux = _data;

        memcpy((void*) aux, (void*)&type, sizeof(uint8_t));
        aux += sizeof(uint8_t);

        memcpy((void*) aux, (void*)&player, sizeof(char));
    } break;
    case PLAYERPOS: {
        alloc_data(sizeof(uint8_t) + sizeof(char) * ((sizeof(PositionMessage) + 3)));
        char* aux = _data;

        memcpy((void*) aux, (void*)&type, sizeof(uint8_t));
        aux += sizeof(uint8_t);
        
        memcpy((void*) aux, &player, sizeof(char));
        aux += sizeof(char);

        memcpy((void*) aux, pos.toString().c_str(), sizeof(char) * (sizeof(PositionMessage) + 3));
    } break; 
    case CANNONANGLE: {
        alloc_data(sizeof(uint8_t) + sizeof(char) * ((sizeof(PositionMessage) + 3)));
        char* aux = _data;

        memcpy((void*) aux, (void*)&type, sizeof(uint8_t));
        aux += sizeof(uint8_t);
        
        memcpy((void*) aux, &player, sizeof(char));
        aux += sizeof(char);

        memcpy((void*) aux, pos.toString().c_str(), sizeof(char) * (sizeof(PositionMessage) + 3));
    } break;
    case BULLETPOS: {
        alloc_data(sizeof(uint8_t) + sizeof(int) * (sizeof(PositionMessage) + 1));
        char* aux = _data;

        memcpy((void*) aux, (void*)&type, sizeof(uint8_t));
        aux += sizeof(uint8_t);
        
        memcpy((void*) aux, &bulletNum, sizeof(int));
        aux += sizeof(int);

        memcpy((void*) aux, pos.toString().c_str(), sizeof(char) * sizeof(PositionMessage) + 1);
    } break;
    case HIT: {
        alloc_data(sizeof(uint8_t) + sizeof(int) + sizeof(char));
        char* aux = _data;

        memcpy((void*) aux, (void*) &type, sizeof(uint8_t));
        aux += sizeof(uint8_t);

        memcpy((void*) aux, &bulletNum, sizeof(int));
        aux += sizeof(int);

        memcpy((void*) aux, &player, sizeof(char));
    } break;

    default:
        break;
    }
}

int Message::from_bin(char* buff){
    char* aux = buff;

    memcpy(&type, aux, sizeof(uint8_t));
    aux += sizeof(uint8_t);

    switch (type)
    {
    case LOGOUT:
    case DEAD:
    case READYTOPLAY:
    case CONNNECTED: {
        memcpy(&player, aux, sizeof(char));
    } break;
    case INPUT:{
        memcpy(&player, aux, sizeof(char));
        aux += sizeof(char);

        char* string = new char[sizeof(InputMessage) * sizeof(char) + 1];
        memcpy(&string[0], aux, sizeof(InputMessage) * sizeof(char) + 1);

        input.fromString(string); delete[] string;
    } break;
    case BULLETPOS:{
        memcpy(&bulletNum, aux, sizeof(int));
        aux += sizeof(int);

        char* string = new char[sizeof(PositionMessage) * sizeof(char) + 1];
        memcpy(&string[0], aux, sizeof(PositionMessage) * sizeof(char) + 1);

        pos.fromString(string); delete[] string;
    } break;
    case PLAYERPOS:{
        memcpy(&player, aux, sizeof(char));
        aux += sizeof(char);

        char* string = new char[(sizeof(PositionMessage) +3) * sizeof(char)];
        memcpy(&string[0], aux, (sizeof(PositionMessage)+3) * sizeof(char));

        pos.fromString(string); delete[] string;
    } break;
    case CANNONANGLE:{
        memcpy(&player, aux, sizeof(char));
        aux += sizeof(char);

        char* string = new char[(sizeof(PositionMessage) +3) * sizeof(char)];
        memcpy(&string[0], aux, (sizeof(PositionMessage)+3) * sizeof(char));

        pos.fromString(string); delete[] string;
    } break;
    case HIT: {
        memcpy(&bulletNum, aux, sizeof(int));
        aux += sizeof(int);

        memcpy(&player, aux, sizeof(char));
    } break;
    default:
        break;
    }

    return 0;
}