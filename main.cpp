#include <iostream>
#include "dungeoncrawler.h"
#include "QApplication"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DungeonCrawler game;  //create game

    return app.exec();     // start Qt event loop
}
