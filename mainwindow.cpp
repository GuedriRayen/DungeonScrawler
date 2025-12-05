#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap background(":/textures/Textures/bloody_frame.png");
    ui->background->setPixmap(background);
    ui->background->setScaledContents(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}
