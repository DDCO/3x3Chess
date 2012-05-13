#include "pawn.h"

Pawn::Pawn(Colour c) : ChessPiece(0,0)
{
    this->colour = c;
    if(this->colour == BLACK)
        this->loadImage(":images/black_pawn_s.png");
    else
        this->loadImage(":images/white_pawn_s.png");
    this->setAcceptDrops(false);
}

std::vector<Position> * Pawn::getAvailableMoves()
{
    return &this->availableMoves;
}

int Pawn::movePiece(Position newpos)
{
    qDebug("Pawn move");
    return 0;
}
