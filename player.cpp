#include "player.h"
#include "game.h"

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
    Game * game = Game::getInstance();
    Player * player = game->getPlayerByTurn(1); // Get player of next turn
    for(int i = 0; i < 3; i++)
    {
        ChessPiece * cp = player->chessPiecesArray[i];
        if( cp->movePermitted(this->chessPiecesArray[2]->pos) ) // is the position of the king a permitted move for the opponent
        {
            qDebug("Check");
            return true;
        }
    }
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
