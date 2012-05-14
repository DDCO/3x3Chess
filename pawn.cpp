#include "pawn.h"
#include "game.h"

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

int Pawn::movePiece(Position newpos)
{
    // if NULL that means the cast failed and it is not PlaceHolder Object, meaning there is a piece in this position
    PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget());

    Game * game = Game::getInstance();

    if( ((this->colour == BLACK) && ((this->pos.row+1) == newpos.row)) || ((this->colour == WHITE) && ((this->pos.row-1) == newpos.row)) )
    {
        if((this->pos.column == newpos.column) && newPosPiece != NULL)
        {
            qDebug("Forward Move is clear");
            game->swapPieces(this->pos,newpos);
        }
        if(newPosPiece == NULL) //Not a PlaceHolder in new position
        {
            if((this->pos.column-1) == newpos.column)
            {
                qDebug("Take Piece on Left");
                game->removePiece(newpos);// Remove piece that was previously there
                game->swapPieces(this->pos,newpos);
            }
            else if((this->pos.column+1) == newpos.column)
            {
                qDebug("Take Piece on Right");
                game->removePiece(newpos);// Remove piece that was previously there
                game->swapPieces(this->pos,newpos);
            }
        }
    }
    return 0;
}
