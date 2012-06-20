#ifndef PLAYER_H
#define PLAYER_H

#include "chesspiece.h"
#include "pawnlabel.h"
#include "bishoplabel.h"
#include "kinglabel.h"

enum PLAYER_TYPE {HUMAN=100, CPU=101};

class Player
{
public:
    Player();
    ~Player();
    BishopLabel * bishop;
    PawnLabel * pawn;
    KingLabel * king;
    static int playerCount;
    void enableDrag(bool);
    int playerID;
    virtual int getType() {return HUMAN;}
};

#endif // PLAYER_H
