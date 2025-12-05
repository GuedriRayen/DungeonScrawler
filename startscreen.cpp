#include "startscreen.h"
#include "ui_startscreen.h"
#include "graphicalui.h"
StartScreen::StartScreen(GraphicalUI* gui,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartScreen),gui(gui)
{
    ui->setupUi(this);
    connect(ui->newGameButton, SIGNAL(clicked()),
            this, SLOT(onStartClicked()));
    QPixmap background(":/textures/Textures/startscreen.png");
    ui->background->setPixmap(background);
    ui->background->setScaledContents(true);
    ui->background->lower();                // Move label behind everything
    ui->background->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    QPixmap gamestartbutton(":/textures/Textures/new_game_button.png");
    QIcon icon(gamestartbutton);

    ui->newGameButton->setIcon(icon);
    ui->newGameButton->setIconSize(gamestartbutton.size());     // icon matches real size
    ui->newGameButton->setFixedSize(gamestartbutton.size());    // button = image size
    ui->newGameButton->setFlat(true);                  // remove borders
    ui->newGameButton->setStyleSheet("background: transparent; border: none;");
    ui->newGameButton->setText("");                    // hide text
}


StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::onStartClicked()
{
    gui->startgame();
}

