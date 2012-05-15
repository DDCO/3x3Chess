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

    //Add player two pieces
    for(int i = 0; i < 3; i++)
    {
        game->p2->chessPiecesArray[i]->setPosition(0,i);
        pGridLayout->addWidget(game->p2->chessPiecesArray[i],0,i,Qt::AlignCenter);
    }

    //Add placeholders (Empty, to allow drop)
    for(int i = 0; i < 3; i++)
    {
        PlaceHolder * ph = new PlaceHolder();
        ph->setPosition(1,i);
        pGridLayout->addWidget(ph,1,i,Qt::AlignCenter);
    }

    //Add player one pieces
    for(int i = 0; i < 3; i++)
    {
        game->p1->chessPiecesArray[i]->setPosition(2,i);
        pGridLayout->addWidget(game->p1->chessPiecesArray[i],2,i,Qt::AlignCenter);
    }

    //set minimum cell width
    pGridLayout->setRowMinimumHeight(1,110);
}

MainWindow::~MainWindow()
{
    delete ui;
}
