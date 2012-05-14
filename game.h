#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "global.h"

class Game
{
public:
    static Game * getInstance();
    Player * p1;
    Player * p2;
    int turnCount;
    void swapPieces();
    void removePiece();
private:
    Game();
    static Game * instance;
};

#endif // GAME_H
