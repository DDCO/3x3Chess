#include "dropablegridlayout.h"

DropableGridLayout::DropableGridLayout(QWidget *parent) :
    QGridLayout(parent)
{
    setAcceptDrops(true);
}

void DropableGridLayout::dropEvent(QDropEvent *event)
{
    qDebug("Contents: %s", event->mimeData()->text());
}

void DropableGridLayout::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

void DropableGridLayout::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}
