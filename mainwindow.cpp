#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pGridLayout = ui->gridLayout;
    pStatusBar = ui->statusBar;

    //Load Background Image
    QImage img;
    if(!img.load(":images/bg.jpg"))
        qWarning("Failed to load bg.jpg");
    ui->bgImage->setPixmap(QPixmap::fromImage(img));

    //Connect menuitem slots
    QObject::connect(ui->actionAI,SIGNAL(triggered()),this,SLOT(slotAIAction()));
    QObject::connect(ui->actionPlayer,SIGNAL(triggered()),this,SLOT(slotPlayerAction()));
}

void MainWindow::slotAIAction()
{
    Game * game = Game::getInstance();
    if(game->turnCount > 0)
    {
        game->close();
        game = Game::getInstance();
    }
    if(ui->gridLayout->isEmpty())
    {
        game->p1 = new Player();
        game->p2 = new AI();
        game->populateLayout();
        game->p1->enableDrag(true);
        ((AI*)game->p2)->setupTree();
    }
}

void MainWindow::slotPlayerAction()
{
    Game * game = Game::getInstance();
    if(game->turnCount > 0)
    {
        game->close();
        game = Game::getInstance();
    }
    if(ui->gridLayout->isEmpty())
    {
        game->p1 = new Player();
        game->p2 = new Player();
        game->populateLayout();
        game->p1->enableDrag(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
