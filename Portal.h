#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"
class Portal: public Tile{
    Portal* destination = nullptr;
public:
    Portal(int row,int col) : Tile("O",row,col){}
    std::pair<bool,Tile*> onEnter(Character* who) override{
        return {true,destination};
    }
    void setDestination(Portal* p){destination = p;}
};
#endif // PORTAL_H
