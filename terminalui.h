#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "AbstractController.h"
#include "AbstractView.h"

class TerminalUI : public AbstractView,public AbstractController {
public:
    void draw(Level* level) override;
    Input move() override;
};
#endif // TERMINALUI_H
