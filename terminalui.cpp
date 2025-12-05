#include "terminalui.h"
#include "level.h"
#include <iostream>
#include <limits>
void TerminalUI::draw(Level* level) {
    std::cout << "Aktuelles Level:\n";
    for (int r = 0; r < level->getHeight(); r++) {
        std::cout << "\"";
        for (int c = 0; c < level->getWidth(); c++) {
            Tile* t = level->showme()[r][c];
            std::cout<<t->getTexture();
        }
        std::cout << "\"\n";
    }
}
Input TerminalUI::move(){

    std::cout << "Bitte Zug eingeben (1-9, 0: Exit): ";
    int move;
    std::cin >> move;
    if (move == 0) {
        Input input;
        input.exit = true; // you need to add this field to Input to exit correctly
        return input;
    }

    int dr = 0, dc = 0;
    Input input;
    switch(move) {
    case 1: input.vb = 1;  input.hb = -1; break;
    case 2: input.vb = 1;  input.hb = 0;  break;
    case 3: input.vb = 1;  input.hb = 1;  break;
    case 4: input.vb = 0;  input.hb = -1; break;
    case 5: input.vb = 0;  input.hb = 0;  break;
    case 6: input.vb = 0;  input.hb = 1;  break;
    case 7: input.vb = -1; input.hb = -1; break;
    case 8: input.vb = -1; input.hb = 0;  break;
    case 9: input.vb = -1; input.hb = 1;  break;
    default: input.vb = 0; input.hb = 0;  break;
    }

    return input;
    //int hb;        // horizontal movement: -1 = left, +1 = right
    //int vb;        // vertical movement: -1 = up, +1 = down
}

