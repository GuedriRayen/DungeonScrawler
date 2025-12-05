#ifndef WALL_H
#define WALL_H
#include "tile.h"
class Wall: public Tile{
public:
    Wall(int row,int col) : Tile("#",row,col){}
    std::pair<bool, Tile*> onEnter(Character* who)  override {
        return {false, nullptr};
    }
};

#endif // WALL_H
