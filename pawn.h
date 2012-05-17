#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"

class Pawn : public ChessPiece
{

public:
    Pawn(Colour);
    std::vector<Position> * getAvailableMoves();
    int movePermitted(Position);
};

#endif // PAWN_H
