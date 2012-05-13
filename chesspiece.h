#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QLabel>
#include <QMouseEvent>
#include <vector>
#include <QImage>
#include <string>
#include <QApplication>
#include "global.h"

struct Position {
    int row;
    int column;
};

enum Colour { BLACK, WHITE };

class ChessPiece : public QLabel
{
    Q_OBJECT

public:
    explicit ChessPiece(QWidget * parent, Qt::WindowFlags f) : QLabel(parent, f)
    {
        this->setAcceptDrops(true);
        pos.row = 0;
        pos.column = 0;
    }
    bool loadImage(std::string);
    virtual std::vector<Position> * getAvailableMoves() {return &this->availableMoves;}
    virtual int movePiece(Position) {return 0;}
    void setPosition(int,int);

protected:
    Colour colour;
    Position pos;
    std::vector<Position> availableMoves;
    QPoint dragStartPosition;
    QImage img;
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void dropEvent(QDropEvent*);
    void dragMoveEvent(QDragMoveEvent*);
    void dragEnterEvent(QDragEnterEvent*);
};

#endif // CHESSPIECE_H
