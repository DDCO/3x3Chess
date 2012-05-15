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
        PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget());
        Game * game = Game::getInstance();

        int offset = abs(newpos.row - this->pos.row);
        if( (this->pos.column+offset == newpos.column) || (this->pos.column-offset == newpos.column) )
        {
            if(!newPosPiece) // If not placeholder(meaning its empty) remove piece
                game->removePiece(newpos);
            game->swapPieces(this->pos,newpos);
            qDebug("Bishop Moved");
        }
    }
    return 0;
}
