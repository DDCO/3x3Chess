#include "bishop.h"
#include "game.h"

Bishop::Bishop(Colour c) : ChessPiece(0,0)
{
    this->colour = c;
    if(this->colour == BLACK)
        this->loadImage(":images/black_bishop_s.png");
    else
        this->loadImage(":images/white_bishop_s.png");
}

std::vector<Position> * Bishop::getAvailableMoves()
{
    return &this->availableMoves;
}

int Bishop::movePiece(Position newpos)
{
    if( (newpos.row != this->pos.row) || (newpos.column != this->pos.column) )
    {
        ChessPiece * cp = (ChessPiece*)pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget();
        PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(cp);
        Game * game = Game::getInstance();

        int offset = abs(newpos.row - this->pos.row);
        if( (this->pos.column+offset == newpos.column) || (this->pos.column-offset == newpos.column) )
        {
            if(!newPosPiece) // If not placeholder
            {
                if(cp->colour != this->colour) //Not the same team
                    game->removePiece(newpos);
                else
                    return 0;
            }
            game->swapPieces(this->pos,newpos);
            qDebug("Bishop Moved");
            return 1;
        }
    }
    return 0;
}
