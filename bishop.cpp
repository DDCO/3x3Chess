#include "bishop.h"
#include "game.h"

Bishop::Bishop(Colour c)
{
    this->colour = c;
}

Position Bishop::getPosition()
{
    Game * game = Game::getInstance();
    Player * p = game->getPlayerByTurn();
    return p->bishop->layoutPosition;
}

int Bishop::movePermitted(Position newpos, BoardState * bs, Position * pos)
{
    if(!pos)
    {
        pos = bs->getPositionByType(BISHOP);
        if(!pos) return 0;
    }

    if( (newpos.row != pos->row) || (newpos.column != pos->column) )
    {
        ChessPiece * cp = bs->board[newpos.row][newpos.column];

        int offset = abs(newpos.row - pos->row);
        if(offset>1)// jumped more then 1 space
        {
            //did it jump over center piece
            ChessPiece * cp = bs->board[1][1];
            if(cp) // is there a piece in the center
                return 0;
        }
        if( (pos->column+offset == newpos.column) || (pos->column-offset == newpos.column) )
        {
            if(cp)
            {
                if(cp->colour != bs->board[pos->row][pos->column]->colour) //Not the same team
                    return 2;
                else
                    return 0;
            }
            return 1;
        }
    }
    return 0;
}

int Bishop::movePermitted(Position newpos)
{
    Position pos = this->getPosition();
    if( (newpos.row != pos.row) || (newpos.column != pos.column) )
    {
        PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget());
        ChessPiece * cp = (ChessPiece*)pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget();

        int offset = abs(newpos.row - pos.row);
        if(offset>1)// jumped more then 1 space
        {
            //did it jump over center piece
            PlaceHolder * placeholder = dynamic_cast<PlaceHolder*>(pGridLayout->itemAtPosition(1,1)->widget());
            if(!placeholder)
                return 0;
        }
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
