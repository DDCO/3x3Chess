#include "boardstate.h"
#include "game.h"

BoardState::BoardState()
{
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            this->board[row][column] = 0;
        }
    }
}

void BoardState::clone()
{
    Game * game = Game::getInstance();

    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            PlaceHolder * ph = dynamic_cast<PlaceHolder*>(pGridLayout->itemAtPosition(row,col)->widget());
            if(!ph)
            {
                ChessPiece * b = dynamic_cast<ChessPiece*>(pGridLayout->itemAtPosition(row,col)->widget());
                this->board[row][col] = b;
            }
        }
    }

    this->turnCount = game->turnCount;
}

void BoardState::copy(BoardState* b)
{
    this->turnCount = b->turnCount;

    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
            this->board[row][column] = b->board[row][column];
    }
}

Position * BoardState::getPositionByType(ChessPieceType type)
{
    Colour c = BLACK;
    if( ( this->turnCount % 2) == 0 )
        c = WHITE;

    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            ChessPiece * temp = this->board[row][column];
            if(temp)
            {
                if( (temp->colour == c) && (temp->getType() == type) )
                {
                    Position * pos = new Position;
                    pos->row = row;
                    pos->column = column;
                    return pos;
                }
            }
        }
    }

    return NULL;
}

void BoardState::move(ChessPieceType type, Position newpos)
{
    Position * prevPos = this->getPositionByType(type);
    this->board[newpos.row][newpos.column] = this->board[prevPos->row][prevPos->column];
    this->board[prevPos->row][prevPos->column] = NULL;
    this->movePieceType = type;
    this->movePosition = newpos;
    this->turnCount++;
}

bool BoardState::operator==(BoardState rhs)
{
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            ChessPiece * cp1 = this->board[row][column];
            ChessPiece * cp2 = rhs.board[row][column];
            if(cp1 && cp2)
            {
                if( (cp1->getType() != cp2->getType()) || (cp1->colour != cp2->colour) )
                    return false;
            }
            else if(!(cp1 == NULL && cp2 == NULL))
                return false;
        }
    }
    return true;
}

int BoardStateNode::countTotalPieces(Colour c)
{
    int count = 0;
    BoardStateNode * child = (BoardStateNode*)this->childNodeList.at(0);
    while(child)
    {
        for(int row = 0; row < 3; row++)
        {
            for(int column = 0; column < 3; column++)
            {
                ChessPiece * cp = child->board[row][column];
                if(cp)
                {
                    if(cp->colour == c)
                        count++;
                }
            }
        }
        if(!child->childNodeList.empty())
            count+= child->countTotalPieces(c);
        child = (BoardStateNode*)child->getNextSibling();
    }
    return count;
}

BoardStateNode::~BoardStateNode()
{
    //Delete Children
    /*while(!this->childNodeList.empty())
    {
        BoardStateNode * temp = (BoardStateNode*)this->childNodeList.back();
        this->childNodeList.pop_back();
        delete temp;
    }*/
}
