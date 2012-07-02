#ifndef GLOBAL_H
#define GLOBAL_H

#include <QGridLayout>
#include <QStatusBar>

extern QGridLayout * pGridLayout;
extern QStatusBar * pStatusBar;

struct Position {
    int row;
    int column;
};

enum Colour { BLACK, WHITE };

enum ChessPieceType { BISHOP=100, PAWN=101, KING=102 };

#endif // GLOBAL_H
