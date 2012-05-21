#ifndef PLAYER_H
#define PLAYER_H

#include "chesspiece.h"
#include "pawnlabel.h"
#include "bishoplabel.h"
#include "kinglabel.h"

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
};

#endif // PLAYER_H
