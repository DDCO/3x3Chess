#ifndef KING_H
#define KING_H

#include "chesspiece.h"

class King : public ChessPiece
{

public:
    King(Colour);
    std::vector<Position> * getAvailableMoves();
    int movePermitted(Position);
};

#endif // KING_H
