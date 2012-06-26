#ifndef GAME_H
#define GAME_H

#include "ai.h"
#include "global.h"
#include <qmessagebox.h>

class Game
{
public:
    static Game * getInstance();
    Player * p1;
    Player * p2;
    int turnCount;
    void swapPieces(Position, Position);
    void removePiece(Position);
    Player * getPlayerByTurn(int turn = 0);
    void populateLayout();
    void close();
    bool hasWon();
    bool hasLost();
    bool isTie();
private:
    Game();
    ~Game();
    static Game * instance;
};

#endif // GAME_H
