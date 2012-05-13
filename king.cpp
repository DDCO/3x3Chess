#include "king.h"

King::King(Colour c) : ChessPiece(0,0)
{
    this->colour = c;
    if(this->colour == BLACK)
        this->loadImage(":images/black_king_s.png");
    else
        this->loadImage(":images/white_king_s.png");
    this->setAcceptDrops(false);
}

std::vector<Position> * King::getAvailableMoves()
{
    return &this->availableMoves;
}

int King::movePiece(Position newpos)
{
    qDebug("King move");
    return 0;
}
