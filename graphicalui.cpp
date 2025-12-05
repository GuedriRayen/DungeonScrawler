#include "graphicalui.h"



GraphicalUI::GraphicalUI() {
    Input temp;
    lastInput = temp;
    mainWindow= new MainWindow();
    startScreen = new StartScreen(this);//pass graphicalui into startscreen

    startScreen->show();

}
GraphicalUI:: ~GraphicalUI(){
    delete mainWindow;
    delete startScreen;
}
void GraphicalUI::draw(Level* level){
    (void)level;
}

void GraphicalUI::startgame()
{
    startScreen->hide();
    mainWindow->show();
}

Input GraphicalUI::move()
{
    return lastInput;
}

