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
    void movePiece(Position);
    virtual int movePermitted(Position) {return 0;}
    virtual Position getPosition() {return position;}
    virtual int getType() {return 0;}
    Colour colour;
    Position position;
};

#endif // CHESSPIECE_H
