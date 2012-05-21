#include "bishop.h"
#include "game.h"

Bishop::Bishop(Colour c)
{
    this->colour = c;
}

std::vector<Position> * Bishop::getAvailableMoves()
{
    return &this->availableMoves;
}

Position Bishop::getPosition()
{
    Game * game = Game::getInstance();
    Player * p = game->getPlayerByTurn();
    return p->bishop->layoutPosition;
}

int Bishop::movePermitted(Position newpos)
{
    Position pos = this->getPosition();
    if( (newpos.row != pos.row) || (newpos.column != pos.column) )
    {
        PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget());
        ChessPiece * cp = (ChessPiece*)pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget();

        int offset = abs(newpos.row - pos.row);
        if( (pos.column+offset == newpos.column) || (pos.column-offset == newpos.column) )
        {
            if(!newPosPiece) // If not placeholder
            {
                if(cp->colour != this->colour) //Not the same team
                    return 2;
                else
                    return 0;
            }
            return 1;
        }
    }
    return 0;
}
