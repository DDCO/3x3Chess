#ifndef DROPABLEGRIDLAYOUT_H
#define DROPABLEGRIDLAYOUT_H

#include <QGridLayout>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QDragMoveEvent>

class DropableGridLayout : public QGridLayout
{
    Q_OBJECT
public:
    explicit DropableGridLayout(QWidget *parent = 0);
    
protected:
    void dropEvent(QDropEvent);
    void dragMoveEvent(QDragMoveEvent);
    void dragEnterEvent(QDragEnterEvent);

signals:
    
public slots:
    
};

#endif // DROPABLEGRIDLAYOUT_H
