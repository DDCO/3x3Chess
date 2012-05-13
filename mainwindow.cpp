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

    //Create placeholders
    for(int i = 0; i < 3; i++)
    {
        this->placeHolders[i] = new ChessPiece(0,0);
        this->placeHolders[i]->setFixedSize(110,110);
    }
}

void MainWindow::slotNewAction()
{
    //Add player two pieces
    for(int i = 0; i < 3; i++)
    {
        p2.chessPiecesArray[i]->setPosition(0,i);
        ui->gridLayout->addWidget(p2.chessPiecesArray[i],0,i,Qt::AlignCenter);
    }

    //Add placeholders (Empty, to allow drop)
    for(int i = 0; i < 3; i++)
    {
        this->placeHolders[i]->setPosition(1,i);
        ui->gridLayout->addWidget(this->placeHolders[i],1,i,Qt::AlignCenter);
    }

    //Add player one pieces
    for(int i = 0; i < 3; i++)
    {
        p1.chessPiecesArray[i]->setPosition(2,i);
        ui->gridLayout->addWidget(p1.chessPiecesArray[i],2,i,Qt::AlignCenter);
    }

    //set minimum cell width
    ui->gridLayout->setRowMinimumHeight(1,110);
}

MainWindow::~MainWindow()
{
    delete ui;

    //Delete placeholders
    for(int i = 0; i < 3; i++)
        delete this->placeHolders[i];
}
