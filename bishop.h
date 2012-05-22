#ifndef BISHOP_H
#define BISHOP_H

#include "chesspiece.h"
#include "boardstate.h"

class Bishop : public ChessPiece
{

public:
    Bishop(Colour);
    static int movePermitted(Position, BoardState * bs = NULL);
    int movePermitted(Position);
    Position getPosition();
    int getType() {return BISHOP;}
};

#endif // BISHOP_H
