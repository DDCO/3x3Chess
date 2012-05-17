#ifndef BISHOP_H
#define BISHOP_H

#include "chesspiece.h"

class Bishop : public ChessPiece
{

public:
    Bishop(Colour);
    std::vector<Position> * getAvailableMoves();
    int movePermitted(Position);
};

#endif // BISHOP_H
