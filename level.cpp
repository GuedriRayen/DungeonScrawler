#include "level.h"
#include "Wall.h"
#include "Floor.h"
#include "Portal.h"
#include "dungeoncrawler.h"
#include "switch.h"
#include "door.h"
#include "Ramp.h"
#include "Pit.h"
#include <typeinfo>
Level::Level(int height, int width):height(height),width(width){}

Level::~Level() {
    for (auto& row : Spielfeld) {
        for (Tile* t : row) {
            delete t;
        }
    }
    for (Character* c : characters) {
        delete c;
    }
}
void Level::generateLevel(std::string l){
    int row = 0, col = 0;
    std::vector<Tile*> currentRow;
    for (char me : l) {
        if (me == '\n') {  // new line = new row
            Spielfeld.push_back(currentRow);
            currentRow.clear();
            row++;
            col = 0;
        } else {
            Tile* newTile=nullptr;
            if (me == '#') {
                newTile = new Wall(row, col);
                currentRow.push_back(newTile);
            } else if (me == '.') {
                newTile = new Floor(row, col);
                currentRow.push_back(newTile);
            } else if (me == 'O') {
                newTile = new Portal(row, col);
                currentRow.push_back(newTile);
            }
            else if (me == '?') {
                newTile = new Switch(row, col);
                currentRow.push_back(newTile);
            } else if (me == 'X' || me == '/') {
                newTile = new Door(row, col);
                currentRow.push_back(newTile);
            }
            else if (me == '_') {
                newTile = new Pit(row, col);
                currentRow.push_back(newTile);
            } else if (me == '<') {
                newTile = new Ramp(row, col);
                currentRow.push_back(newTile);
            }
            col++;
        }
    }
    if (!currentRow.empty()) {
        Spielfeld.push_back(currentRow);// push the last row if the layout didn't end with a newline
    }
    height = Spielfeld.size();       // number of rows
    width = Spielfeld[0].size();  //number of columns in the 1st rowq
}
Level::Level(GraphicalUI* ui){
    generateLevel(l);
    /*Switch* sw = nullptr;
    Door* door = nullptr;
    Ramp* ramp= nullptr;
    Pit* pit=nullptr;
    Portal* tp = nullptr;
    for (auto& row : Spielfeld){
        for ( auto* t : row){
            if(!tp){
                tp = dynamic_cast<Portal*>(t);
                tp->setDestination(tp);
            }
        }
    }*/
    /*for (auto& row : Spielfeld) {
        for (auto* t : row) {
            if (!sw)
                sw = dynamic_cast<Switch*>(t);
            if (!door)
                door = dynamic_cast<Door*>(t);
        }
    }

    if (sw && door)
        sw->attach(door);   //door/switch test*/
    Portal* p1 = nullptr;
    Portal* p2 = nullptr;

    for (auto& row : Spielfeld) { // verbindi zouz portlouet kol zouz maa baadhhom
        for (auto* t : row) {
            if (!p1) p1 = dynamic_cast<Portal*>(t);
            else if (!p2 && p2!=p1) p2 = dynamic_cast<Portal*>(t);
        }
    }

    if (p1 && p2) {
        p1->setDestination(p2);
        p2->setDestination(p1);
    }
    DungeonCrawler* pt;
    Character* hero = new Character("H");
    characters.push_back(hero);
    hero->setController(ui);

    //hottou fi awel floor;
    for (size_t i = 0; i < Spielfeld.size(); i++) {
        for (size_t j = 0; j < Spielfeld[i].size(); j++) {
            if (dynamic_cast<Floor*>(Spielfeld[i][j])) {
                Spielfeld[i][j]->setCharacter(hero);
                hero->setTile(Spielfeld[i][j]);
                i = Spielfeld.size(); // exit both loops
                break;
            }
        }
    }
}

Level::Level(const Level &other)
{
    height = other.height;
    width = other.width;

    // Deep copy the tile grid
    for (auto& row : other.Spielfeld) {
        std::vector<Tile*> newRow;
        for (auto* t : row) {
            Tile* copy = nullptr;

            if (typeid(*t) == typeid(Wall))   copy = new Wall(*static_cast<Wall*>(t));
            else if (typeid(*t) == typeid(Floor)) copy = new Floor(*static_cast<Floor*>(t));
            else if (typeid(*t) == typeid(Portal)) copy = new Portal(*static_cast<Portal*>(t));
            else if (typeid(*t) == typeid(Switch)) copy = new Switch(*static_cast<Switch*>(t));
            else if (typeid(*t) == typeid(Door))   copy = new Door(*static_cast<Door*>(t));
            else if (typeid(*t) == typeid(Pit))    copy = new Pit(*static_cast<Pit*>(t));
            else if (typeid(*t) == typeid(Ramp))   copy = new Ramp(*static_cast<Ramp*>(t));

            newRow.push_back(copy);
        }
        Spielfeld.push_back(newRow);
    }


    for (auto* c : other.characters) {
        // copy lcharacters ama matcopich el controller teehom khater tetnek omha
        Character* clone = new Character(c->getTexture());
        characters.push_back(clone);
    }

}

Level &Level::operator=(const Level &other)
{
    if (this == &other) return *this;  // self assignment guard(mehich haja tnajem testaghna aleha level A = A tahche fl prgrm)

    // Free old memory
    this->~Level();

    // Copy exactly like the copy constructor
    height = other.height;
    width = other.width;

    for (auto& row : other.Spielfeld) {
        std::vector<Tile*> newRow;
        for (auto* t : row) {
            Tile* copy = nullptr;

            if (typeid(*t) == typeid(Wall))   copy = new Wall(*static_cast<Wall*>(t));
            else if (typeid(*t) == typeid(Floor)) copy = new Floor(*static_cast<Floor*>(t));
            else if (typeid(*t) == typeid(Portal)) copy = new Portal(*static_cast<Portal*>(t));
            else if (typeid(*t) == typeid(Switch)) copy = new Switch(*static_cast<Switch*>(t));
            else if (typeid(*t) == typeid(Door))   copy = new Door(*static_cast<Door*>(t));
            else if (typeid(*t) == typeid(Pit))    copy = new Pit(*static_cast<Pit*>(t));
            else if (typeid(*t) == typeid(Ramp))   copy = new Ramp(*static_cast<Ramp*>(t));

            newRow.push_back(copy);
        }
        Spielfeld.push_back(newRow);
    }

    for (auto* c : other.characters) {
        Character* clone = new Character(c->getTexture());
        characters.push_back(clone);
    }

    return *this;
}

Tile *Level::getTile(int row, int col){
    return Spielfeld[row][col];
}

