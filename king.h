#ifndef KING_H
#define KING_H

#include "chesspiece.h"
#include "boardstate.h"

class King : public ChessPiece
{

public:
    King(Colour);
    static int movePermitted(Position, BoardState * bs = NULL);
    int movePermitted(Position);
    Position getPosition();
    int getType() {return KING;}
    static bool isCheck(Position);
    static bool isCheckMate(BoardState);
};

#endif // KING_H
