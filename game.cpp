#include "game.h"

Game * Game::instance = NULL;

Game::Game()
{
    this->turnCount = 0;

    //Create new players
    this->p1 = new Player();
    this->p2 = new Player();

    this->p1->enableDrag(true);
}

Game * Game::getInstance()
{
    if(!Game::instance)
        Game::instance = new Game();
    return Game::instance;
}

void Game::swapPieces(Position pos1, Position pos2)
{
    DragableLabel * label1 = (DragableLabel*)pGridLayout->itemAtPosition(pos1.row,pos1.column)->widget();
    DragableLabel * label2 = (DragableLabel*)pGridLayout->itemAtPosition(pos2.row,pos2.column)->widget();

    label1->layoutPosition.row = pos2.row;
    label1->layoutPosition.column = pos2.column;
    label2->layoutPosition.row = pos1.row;
    label2->layoutPosition.column = pos1.column;

    //swap objects in gridlayout
    pGridLayout->removeWidget(label1);
    pGridLayout->removeWidget(label2);
    pGridLayout->addWidget(label1,pos2.row,pos2.column,Qt::AlignCenter);
    pGridLayout->addWidget(label2,pos1.row,pos1.column,Qt::AlignCenter);

    Player * player = this->getPlayerByTurn();
    player->enableDrag(false);

    this->turnCount++;

    player = this->getPlayerByTurn();
    player->king->isCheck();
    player->enableDrag(true);
}

void Game::removePiece(Position pos)
{
    DragableLabel * label = (DragableLabel*)pGridLayout->itemAtPosition(pos.row,pos.column)->widget();
    pGridLayout->removeWidget(label);
    label->hide();

    pGridLayout->addWidget(new PlaceHolder(pos.row,pos.column),pos.row,pos.column,Qt::AlignCenter);
}

Player * Game::getPlayerByTurn(int turn)
{
    if( ( (this->turnCount+turn) % 2) == 0 )
        return p1;
    return p2;
}

void Game::close()
{
    delete Game::instance;
}

void Game::populateLayout()
{
    this->p1 = new Player();
    this->p2 = new Player();

    pGridLayout->addWidget(p2->bishop,0,0,Qt::AlignCenter);
    pGridLayout->addWidget(p2->pawn,0,1,Qt::AlignCenter);
    pGridLayout->addWidget(p2->king,0,2,Qt::AlignCenter);
    pGridLayout->addWidget(new PlaceHolder(1,0),1,0,Qt::AlignCenter);
    pGridLayout->addWidget(new PlaceHolder(1,1),1,1,Qt::AlignCenter);
    pGridLayout->addWidget(new PlaceHolder(1,2),1,2,Qt::AlignCenter);
    pGridLayout->addWidget(p1->bishop,2,0,Qt::AlignCenter);
    pGridLayout->addWidget(p1->pawn,2,1,Qt::AlignCenter);
    pGridLayout->addWidget(p1->king,2,2,Qt::AlignCenter);

    pGridLayout->setRowMinimumHeight(1,110);

    p1->enableDrag(true);
}

Game::~Game()
{
    for(int col = 0; col < 3; col++)
    {
        for(int row = 0; row < 3; row++)
        {
            DragableLabel * label = (DragableLabel*)pGridLayout->itemAtPosition(row,col)->widget();
            pGridLayout->removeWidget(label);

            PlaceHolder * ph = dynamic_cast<PlaceHolder*>(label);
            if(ph)
                delete label;
        }
    }

    delete p1;
    delete p2;

    Game::instance = NULL;
}
