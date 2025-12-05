#ifndef PIT_H
#define PIT_H
#include "tile.h"
#include "Ramp.h"
class Pit : public Tile{
public:
    Pit(int r,int c):Tile("_",r,c){}
    std::pair<bool,Tile*> onEnter(Character* who) override {
        return {true,nullptr};
    }
    bool onLeave(Tile* destTile,Character* who) override{
        if((dynamic_cast<Pit*>(destTile))||(dynamic_cast<Ramp*>(destTile))){//only can leave if it's to a ramp or to another pit
            return true;
        }
        else{return false;}
    }
};

#endif // PIT_H
