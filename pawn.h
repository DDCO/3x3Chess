#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"
#include "boardstate.h"

class Pawn : public ChessPiece
{

public:
    Pawn(Colour);
    static int movePermitted(Position, BoardState * bs = NULL);
    int movePermitted(Position);
    int getType() {return PAWN;}
    Position getPosition();
};

#endif // PAWN_H
