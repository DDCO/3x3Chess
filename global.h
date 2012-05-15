#ifndef GLOBAL_H
#define GLOBAL_H

#include <QGridLayout>

extern QGridLayout * pGridLayout;

struct Position {
    int row;
    int column;
};

enum Colour { BLACK, WHITE };

#endif // GLOBAL_H
