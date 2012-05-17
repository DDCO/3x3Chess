#include "king.h"
#include "game.h"

King::King(Colour c) : ChessPiece(0,0)
{
    this->colour = c;
    if(this->colour == BLACK)
        this->loadImage(":images/black_king_s.png");
    else
        this->loadImage(":images/white_king_s.png");
}

std::vector<Position> * King::getAvailableMoves()
{
    return &this->availableMoves;
}

int King::movePiece(Position newpos)
{
    if( (newpos.row != this->pos.row) || (newpos.column != this->pos.column) ) // not the same spot as it is currently
    {
        int colOffset = abs(this->pos.column - newpos.column);
        int rowOffset = abs(this->pos.row - newpos.row);
        if( colOffset <= 1 && rowOffset <=1  )
        {
            ChessPiece * cp = (ChessPiece*)pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget();
            PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(cp);
            Game * game = Game::getInstance();

            if(!newPosPiece) // Not a placeholder
            {
                if(cp->colour != this->colour) // not the same team
                    game->removePiece(newpos);
                else
                    return 0;
            }
            game->swapPieces(newpos, this->pos);
            qDebug("King Moved");
            return 1;
        }
    }
    return 0;
}
