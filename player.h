#ifndef PLAYER_H
#define PLAYER_H

#include "chesspiece.h"
#include "pawn.h"
#include "bishop.h"
#include "king.h"

class Player
{
public:
    Player();
    ~Player();
    ChessPiece * chessPiecesArray[3];
    bool isCheck();
    bool isCheckMate();
    static int playerCount;
    void enableDrag(bool);
};

#endif // PLAYER_H
