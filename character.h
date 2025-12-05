#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "AbstractController.h"
class Tile;

class Character
{
    std::string Texture;
    Tile* tile;
    AbstractController* controller;

public:
    Character(std::string Texture, AbstractController* controller = nullptr);
    std::string getTexture(){return Texture;}
    void setTile(Tile* newTile){tile=newTile;}
    Tile* getTile(){return tile;}
    Input move() ;
    void setController(AbstractController* controller);
};

#endif // CHARACTER_H
