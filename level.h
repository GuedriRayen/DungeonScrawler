#ifndef LEVEL_H
#define LEVEL_H

#include "tile.h"

#include <vector>
class TerminalUI;
class GraphicalUI;
class Level
{
    std::vector<std::vector<Tile*>> Spielfeld;
    std::vector<Character*> characters;
    int height,width;
    const std::string l = {
        "##########\n"
        "#O.......#\n"
        "#...<....#\n"
        "#..___...#\n"
        "#..___...#\n"
        "#........#\n"
        "#######X##\n"
        "#O.......#\n"
        "#...?....#\n"
        "##########\n"
    };
public:
    Level(int height,int width);
    ~Level();
    Level(GraphicalUI* ui);
    Tile* getTile(int row, int col);
    void generateLevel(std::string l);
    int playerscount(){return characters.size();}
    const Tile* getTile(int row,int col) const{return Spielfeld[row][col];}
    void placeCharacter(Character*c , int row,int col){
        Spielfeld[row][col]->setCharacter(c);
        c->setTile(Spielfeld[row][col]);
    }
    int getHeight(){return height;}
    int getWidth(){return width;}
    auto getaSpecificPlayer(int i){return characters[i];}
    std::vector<std::vector<Tile*>> showme(){return Spielfeld;}
    Level &operator =(const Level &other);
    Level(const Level &other);
};

#endif // LEVEL_H
