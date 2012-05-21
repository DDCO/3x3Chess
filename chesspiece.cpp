#include "chesspiece.h"
#include "game.h"

void ChessPiece::movePiece(Position newpos)
{
    Game * game = Game::getInstance();
    switch(this->movePermitted(newpos))
    {
        case 2:
            game->removePiece(newpos);
        case 1:
            game->swapPieces(newpos,this->getPosition());
        break;
        case 0:
            qDebug("Move not permitted");
        break;
    }
}
