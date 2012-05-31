#ifndef BOARDSTATE_H
#define BOARDSTATE_H

#include "chesspiece.h"
#include "node.h"
#include "global.h"

class BoardState
{
public:
    BoardState();
    void clone();
    void copy(BoardState*);
    Position * getPositionByType(ChessPieceType);
    void move(ChessPieceType type, Position newpos);
    bool operator==(BoardState);
    ChessPieceType movePieceType;
    Position movePosition;
    int turnCount;
    ChessPiece * board[3][3];
};

class BoardStateNode : public BoardState, public Node
{
public:
    int countTotalPieces(Colour);
};

#endif // BOARDSTATE_H