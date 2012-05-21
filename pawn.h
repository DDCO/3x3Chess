#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"
#include "dragablelabel.h"

class Pawn : public ChessPiece
{

public:
    Pawn(Colour);
    std::vector<Position> * getAvailableMoves();
    int movePermitted(Position);
    Position getPosition();
};

#endif // PAWN_H
