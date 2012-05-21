#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pGridLayout = ui->gridLayout;

    //Load Background Image
    QImage img;
    if(!img.load(":images/bg.jpg"))
        qWarning("Failed to load bg.jpg");
    ui->bgImage->setPixmap(QPixmap::fromImage(img));

    //Connect New menuitem slot
    QObject::connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(slotNewAction()));
}

void MainWindow::slotNewAction()
{
    Game * game = Game::getInstance();
    if(game->turnCount > 0)
    {
        game->close();
        game = Game::getInstance();
    }

    game->populateLayout();
}

MainWindow::~MainWindow()
{
    delete ui;
}
