#include "player.h"

int Player::playerCount = 0;

Player::Player()
{
    Player::playerCount++;

    Colour c = WHITE;
    if((Player::playerCount % 2) == 0)
        c = BLACK;

    this->chessPiecesArray[0] = (ChessPiece*)new Bishop(c);
    this->chessPiecesArray[1] = (ChessPiece*)new Pawn(c);
    this->chessPiecesArray[2] = (ChessPiece*)new King(c);
}

bool Player::isCheck()
{
    return false;
}

bool Player::isCheckMate()
{
    return false;
}

Player::~Player()
{
    delete this->chessPiecesArray[0];
    delete this->chessPiecesArray[1];
    delete this->chessPiecesArray[2];
    Player::playerCount = 0;
}
