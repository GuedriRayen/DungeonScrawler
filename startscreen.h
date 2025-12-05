#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QDialog>
class GraphicalUI;

namespace Ui {
class StartScreen;
}

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit StartScreen(GraphicalUI* gui, QWidget *parent = nullptr);
    ~StartScreen();

private slots:
    void onStartClicked();

private:
    Ui::StartScreen *ui;
    GraphicalUI* gui;
};


#endif // STARTSCREEN_H
