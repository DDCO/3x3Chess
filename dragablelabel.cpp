#include "dragablelabel.h"

bool DragableLabel::loadImage(std::string filename)
{
    // Load + set image
    if(!this->img.load(filename.c_str()))
        return false;
    this->setPixmap(QPixmap::fromImage(this->img));
    return true;
}

void DragableLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        this->dragStartPosition = event->pos();
}

void DragableLabel::mouseMoveEvent(QMouseEvent *event)
{
    if(!(event->buttons() & Qt::LeftButton))
        return;
    if((event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance())
        return;
    if(!this->enableDrag)
        return;

    QDrag * drag = new QDrag(this);
    QMimeData * mimeData = new QMimeData();

    char text[10];
    sprintf(text,"%d,%d",this->layoutPosition.row,this->layoutPosition.column);

    mimeData->setText(text);

    drag->setPixmap(QPixmap::fromImage(this->img));
    drag->setMimeData(mimeData);

    Qt::DropAction dropAction = drag->exec();
    //drag->start(); //either one works
}

void DragableLabel::dropEvent(QDropEvent *event)
{
    std::string prevPosStr = event->mimeData()->text().toLatin1().data();
    std::string strRow, strColumn;

    //Split string using the ',' as a delimiter
    size_t found;
    found = prevPosStr.find(',');
    if(found != std::string::npos)
    {
        strRow = prevPosStr.substr(0,(int)found);
        strColumn = prevPosStr.substr((int)found+1);
    }

    //Convert str to int
    Position prevPos;
    prevPos.row = atoi(strRow.c_str());
    prevPos.column = atoi(strColumn.c_str());

    //get Object from the position
    ChessPiece * p = dynamic_cast<ChessPiece*>(pGridLayout->itemAtPosition(prevPos.row,prevPos.column)->widget());

    //move piece to new position(the position of the placeholder)
    p->movePiece(this->layoutPosition);

    event->acceptProposedAction();
}

void DragableLabel::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

void DragableLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}
