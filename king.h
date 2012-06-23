#ifndef KING_H
#define KING_H

#include "chesspiece.h"
#include "boardstate.h"

class King : public ChessPiece
{

public:
    King(Colour);
    static int movePermitted(Position, BoardState * bs = NULL, bool useCheckCondition = true);
    int movePermitted(Position);
    Position getPosition();
    int getType() {return KING;}
    static bool isCheck(Position, BoardState * bs = NULL);
};

#endif // KING_H
