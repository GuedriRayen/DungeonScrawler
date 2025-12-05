#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
//#include "terminalui.h"
#include "graphicalui.h"

class DungeonCrawler
{
    GraphicalUI* ui;
    Level* level;
public:
    DungeonCrawler();
    Level *getLevel();
    bool turn();
    ~DungeonCrawler();
    GraphicalUI* getUI(){return ui;}//linna kenet TerminalUI zeda
};

#endif // DUNGEONCRAWLER_H
