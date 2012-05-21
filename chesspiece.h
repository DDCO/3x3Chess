#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QLabel>
#include <QMouseEvent>
#include <vector>
#include <QImage>
#include <string>
#include <QApplication>
#include "global.h"

class ChessPiece
{

public:
    virtual std::vector<Position> * getAvailableMoves() {return &this->availableMoves;}
    void movePiece(Position);
    virtual int movePermitted(Position) {return 0;}
    virtual Position getPosition() {return position;}
    Colour colour;
    Position position;

protected:
    std::vector<Position> availableMoves;
};

#endif // CHESSPIECE_H
