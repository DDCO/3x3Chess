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

void Player::enableDrag(bool enabled)
{
    for(int i = 0; i < 3; i++)
        this->chessPiecesArray[i]->enableDrag = enabled;
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
    Player::playerCount = 0;
}
