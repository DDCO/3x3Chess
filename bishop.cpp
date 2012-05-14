#include "bishop.h"

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
    qDebug("Bishop move");
    return 0;
}
