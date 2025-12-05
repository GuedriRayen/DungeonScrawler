#ifndef DOOR_H
#define DOOR_H
#include "tile.h"
#include "Passive.h"
class Door : public Tile, public Passive
{
    bool open = false;
public:
    Door(int r,int c):Tile("/",r,c){}
    void notify() override{
        open = !open;
        if (open){
            texture = "/";
        }
        else{texture="X";}
    }
    std::pair<bool,Tile*> onEnter(Character* who) override {
        return {open,nullptr};
    }
};

#endif // DOOR_H
