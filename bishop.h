#ifndef BISHOP_H
#define BISHOP_H

#include "chesspiece.h"

class Bishop : public ChessPiece
{

public:
    Bishop(Colour);
    std::vector<Position> * getAvailableMoves();
    int movePiece(Position);
};

#endif // BISHOP_H
