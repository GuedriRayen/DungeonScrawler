#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler() :level(nullptr),ui(nullptr){
    ui = new GraphicalUI;
    level = new Level(ui);
}
DungeonCrawler::~DungeonCrawler(){
    delete level;
    delete ui;
}
Level* DungeonCrawler::getLevel() {
    return level;
}

bool DungeonCrawler::turn() {//linna ysir lmove taa lplayer fl map
    ui->draw(level);
    for(size_t i= 0;i<level->playerscount();i++){
        Character* player =level->getaSpecificPlayer(i) ;
        Input input =player->move();//input for this player
        if (input.exit) return false;
        Tile* currentTile = player->getTile();
        int newRow = currentTile->getRow() + input.vb;
        int newCol = currentTile->getCol() + input.hb;

        if (newRow >= 0 && newRow < level->getHeight() &&
            newCol >= 0 && newCol < level->getWidth()) {
            //linna el conditions taa onLeave and onEnter
            Tile* current = player->getTile();
            Tile* dest = level->getTile(newRow, newCol);

            auto enterResult = dest->onEnter(player);
            bool canEnter = enterResult.first;
            //hedhi waktelli lPortal ykharrej destination x_x
            Tile* finalDest = enterResult.second;
            if (!finalDest)  finalDest = dest;
            if (current->onLeave(finalDest, player) && canEnter) {
                current->moveTo(finalDest, player);
            }
        }
    }
    return true;
}



/*Tile* finalDest = enterResult.second; x_x
            if (!finalDest) finalDest = dest;*/
