#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include "AbstractController.h"
#include "AbstractView.h"
#include "mainwindow.h"
#include "startscreen.h"

class GraphicalUI:public AbstractView, public AbstractController
{
    Input lastInput;
    MainWindow* mainWindow;
    StartScreen* startScreen;
public:
    GraphicalUI();
    void draw(Level* level) override;
    void startgame();
    Input move() override;

    ~GraphicalUI();
};

#endif // GRAPHICALUI_H
