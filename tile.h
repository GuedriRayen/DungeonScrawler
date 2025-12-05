#ifndef TILE_H
#define TILE_H
#include <string>
#include "character.h"
class Tile
{
protected:
    std::string texture;
    Character* character;
    const int row, col;
    Tile(std::string texture,int row,int col);
public:
    std::string getTexture(){
        if (character != nullptr) {
            return character->getTexture();
        }
        return texture;
    }
    bool hasCharacter(){
        return character != nullptr;
    }
    const int getRow(){return row;}
    const int getCol(){return col;}
    bool moveTo(Tile* destTile,Character* who){
        this->character = nullptr;
        destTile->character = who;
        who->setTile(destTile);
        return true;
    }
    virtual std::pair<bool,Tile*> onEnter(Character* who){
        return {true,this};
    }
    virtual bool onLeave(Tile* destTile,Character* who){
        return true;
    }
    void setCharacter(Character* c){character = c;}
};

#endif // TILE_H
