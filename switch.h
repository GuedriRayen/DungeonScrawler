#ifndef SWITCH_H
#define SWITCH_H
#include "tile.h"
#include "Active.h"
class Switch: public Tile, public Active{
public:
    Switch(int r, int c) : Tile("?",r, c) {}
    std::pair<bool,Tile*> onEnter(Character* who) override {
        //activate();
        return {true,nullptr};
    }
};

#endif // SWITCH_H
