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
    void swapPieces(Position, Position);
    void removePiece(Position);
    void close();
private:
    Game();
    ~Game();
    static Game * instance;
};

#endif // GAME_H
