#ifndef DRAGABLELABEL_H
#define DRAGABLELABEL_H

#include <QLabel>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <vector>
#include <QImage>
#include <string>
#include <QApplication>
#include "chesspiece.h"
#include "global.h"

class DragableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit DragableLabel(QWidget * parent, Qt::WindowFlags f) : QLabel(parent, f)
    {
        this->setAcceptDrops(true);
        this->setFixedSize(110,110);
        this->enableDrag = false;
        this->layoutPosition.row = 0;
        this->layoutPosition.column = 0;
    }
    bool loadImage(std::string);
    bool enableDrag;
    Position layoutPosition;

protected:
    QPoint dragStartPosition;
    QImage img;
    void mousePressEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void dropEvent(QDropEvent*);
    void dragMoveEvent(QDragMoveEvent*);
    void dragEnterEvent(QDragEnterEvent*);
};

class PlaceHolder : public DragableLabel, public ChessPiece
{
    public:
        PlaceHolder(int row,int column) : DragableLabel(0,0)
        {
            this->layoutPosition.row = row;
            this->layoutPosition.column = column;
        }
};

#endif
