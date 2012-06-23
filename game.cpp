#include "game.h"

Game * Game::instance = NULL;

Game::Game()
{
    this->turnCount = 0;
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

    if(this->hasWon())
    {
        QMessageBox::information(NULL,"Game Over","Player 1 wins",QMessageBox::Ok);
        return;
    }
    if(this->hasLost())
    {
        QMessageBox::information(NULL,"Game Over","Player 2 wins",QMessageBox::Ok);
        return;
    }

    this->turnCount++;

    player = this->getPlayerByTurn();
    player->enableDrag(true);

    if(this->p2->getType() == CPU)
    {
        AI * ai = (AI*)this->p2;
        ai->updateTree();

        //if its AI turn
        if(player->playerID == 2)
        {
            if(ai->movesAvailable())
                ai->MaxMove();
            else
            {
                qDebug("Game Over");
                this->p2->enableDrag(false);
            }
        }
    }
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
    pGridLayout->addWidget(p2->bishop,0,0,Qt::AlignCenter);
    pGridLayout->addWidget(p2->pawn,0,1,Qt::AlignCenter);
    pGridLayout->addWidget(p2->king,0,2,Qt::AlignCenter);
    pGridLayout->addWidget(new PlaceHolder(1,0),1,0,Qt::AlignCenter);
    pGridLayout->addWidget(new PlaceHolder(1,1),1,1,Qt::AlignCenter);
    pGridLayout->addWidget(new PlaceHolder(1,2),1,2,Qt::AlignCenter);
    pGridLayout->addWidget(p1->bishop,2,2,Qt::AlignCenter);
    pGridLayout->addWidget(p1->pawn,2,1,Qt::AlignCenter);
    pGridLayout->addWidget(p1->king,2,0,Qt::AlignCenter);

    pGridLayout->setRowMinimumHeight(1,110);
}

bool Game::hasWon()
{
    BoardState currentBoardState;
    currentBoardState.clone();

    BoardState winningBoardState;
    winningBoardState.board[0][0] = p1->bishop;
    winningBoardState.board[0][1] = p1->pawn;
    winningBoardState.board[1][0] = p1->king;
    winningBoardState.board[2][2] = p2->king;
    if(winningBoardState == currentBoardState)
        return true;
    return false;
}

bool Game::hasLost()
{
    BoardState currentBoardState;
    currentBoardState.clone();

    BoardState winningBoardState;
    winningBoardState.board[1][1] = p2->bishop;
    winningBoardState.board[0][1] = p2->pawn;
    winningBoardState.board[0][2] = p2->king;
    winningBoardState.board[2][0] = p1->king;
    winningBoardState.board[2][1] = p1->pawn;
    if(winningBoardState == currentBoardState)
        return true;
    return false;
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
