#include "pawn.h"

Pawn::Pawn(Colour c) : ChessPiece(0,0)
{
    this->colour = c;
    if(this->colour == BLACK)
        this->loadImage(":images/black_pawn_s.png");
    else
        this->loadImage(":images/white_pawn_s.png");
}

std::vector<Position> * Pawn::getAvailableMoves()
{
    return &this->availableMoves;
}

int Pawn::movePermitted(Position newpos)
{
    ChessPiece * cp = (ChessPiece*)pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget();
    // if NULL that means the cast failed and it is not PlaceHolder Object, meaning there is a piece in this position
    PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(cp);

    if( ((this->colour == BLACK) && ((this->pos.row+1) == newpos.row)) || ((this->colour == WHITE) && ((this->pos.row-1) == newpos.row)) )
    {
        if((this->pos.column == newpos.column) && newPosPiece != NULL)
            return 1;
        if(newPosPiece == NULL && (cp->colour != this->colour) ) //Not a PlaceHolder and chesspiece is not the same team
        {
            if((this->pos.column-1) == newpos.column)
                return 2;
            else if((this->pos.column+1) == newpos.column)
                return 2;
        }
    }
    return 0;
}
