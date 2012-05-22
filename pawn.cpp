#include "pawn.h"
#include "game.h"

Pawn::Pawn(Colour c)
{
    this->colour = c;
}

Position Pawn::getPosition()
{
    Game * game = Game::getInstance();
    Player * p = game->getPlayerByTurn();
    return p->pawn->layoutPosition;
}

int Pawn::movePermitted(Position newpos, BoardState * bs)
{
    ChessPiece * cp = bs->board[newpos.row][newpos.column];
    Position * pos = bs->getPositionByType(PAWN);
    if(!pos)
        return 0;

    Colour colour = bs->board[pos->row][pos->column]->colour;

    if( ((colour == BLACK) && ((pos->row+1) == newpos.row)) || ((colour == WHITE) && ((pos->row-1) == newpos.row)) )
    {
        if((pos->column == newpos.column) && cp == NULL)
            return 1;
        if(cp && (cp->colour != colour) )
        {
            if((pos->column-1) == newpos.column)
                return 2;
            else if((pos->column+1) == newpos.column)
                return 2;
        }
    }
    return 0;
}

int Pawn::movePermitted(Position newpos)
{
    ChessPiece * cp = (ChessPiece*)pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget();
    // if NULL that means the cast failed and it is not PlaceHolder Object, meaning there is a piece in this position
    PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget());
    Position pos = this->getPosition();

    if( ((this->colour == BLACK) && ((pos.row+1) == newpos.row)) || ((this->colour == WHITE) && ((pos.row-1) == newpos.row)) )
    {
        if((pos.column == newpos.column) && newPosPiece != NULL)
            return 1;
        if(newPosPiece == NULL && (cp->colour != this->colour) ) //Not a PlaceHolder and chesspiece is not the same team
        {
            if((pos.column-1) == newpos.column)
                return 2;
            else if((pos.column+1) == newpos.column)
                return 2;
        }
    }
    return 0;
}
