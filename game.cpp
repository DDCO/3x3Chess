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
    ChessPiece * piece1 = (ChessPiece*)pGridLayout->itemAtPosition(pos1.row,pos1.column)->widget();
    ChessPiece * piece2 = (ChessPiece*)pGridLayout->itemAtPosition(pos2.row,pos2.column)->widget();

    //Update position in object
    piece1->setPosition(pos2.row,pos2.column);
    piece2->setPosition(pos1.row,pos1.column);

    //swap objects in gridlayout
    pGridLayout->addWidget(piece1,pos2.row,pos2.column,Qt::AlignCenter);
    pGridLayout->addWidget(piece2,pos1.row,pos1.column,Qt::AlignCenter);

    Player * player = this->getPlayerByTurn();
    player->enableDrag(false);
    this->turnCount++;
    player = this->getPlayerByTurn();
    player->enableDrag(true);
}

void Game::removePiece(Position pos)
{
    PlaceHolder * ph = new PlaceHolder();

    ChessPiece * piece = (ChessPiece*)pGridLayout->itemAtPosition(pos.row,pos.column)->widget();
    pGridLayout->removeWidget(piece);
    delete piece;

    pGridLayout->addWidget(ph,pos.row,pos.column,Qt::AlignCenter);
}

Player * Game::getPlayerByTurn()
{
    if((this->turnCount % 2) == 0)
        return p1;
    return p2;
}

void Game::close()
{
    delete Game::instance;
}

Game::~Game()
{
    for(int col = 0; col < 3; col++)
    {
        for(int row = 0; row < 3; row++)
        {
            ChessPiece * piece = (ChessPiece*)pGridLayout->itemAtPosition(row,col)->widget();
            pGridLayout->removeWidget(piece);
            delete piece;
        }
    }

    delete p1;
    delete p2;

    Game::instance = NULL;
}
