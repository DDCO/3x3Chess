#ifndef KING_H
#define KING_H

#include "chesspiece.h"
#include "dragablelabel.h"

class King : public ChessPiece
{

public:
    King(Colour);
    std::vector<Position> * getAvailableMoves();
    int movePermitted(Position);
    Position getPosition();
    bool isCheck();
    bool isCheckMate();
};

#endif // KING_H
