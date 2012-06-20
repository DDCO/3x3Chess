#include "player.h"

int Player::playerCount = 0;

Player::Player()
{
    Player::playerCount++;

    Colour c = WHITE;
    this->playerID = 1;
    if((Player::playerCount % 2) == 0)
    {
        c = BLACK;
        this->playerID = 2;
    }

    this->bishop = new BishopLabel(c);
    this->pawn = new PawnLabel(c);
    this->king = new KingLabel(c);
}

void Player::enableDrag(bool enabled)
{
    this->bishop->enableDrag = enabled;
    this->pawn->enableDrag = enabled;
    this->king->enableDrag = enabled;
}

Player::~Player()
{
    // Game object removes them
    delete this->bishop;
    delete this->pawn;
    delete this->king;
    Player::playerCount--;
}
