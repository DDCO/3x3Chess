#ifndef BISHOP_H
#define BISHOP_H

#include "chesspiece.h"
#include "dragablelabel.h"

class Bishop : public ChessPiece
{

public:
    Bishop(Colour);
    std::vector<Position> * getAvailableMoves();
    int movePermitted(Position);
    Position getPosition();
};

#endif // BISHOP_H
