#include "king.h"
#include "game.h"

King::King(Colour c)
{
    this->colour = c;
}

Position King::getPosition()
{
    Game * game = Game::getInstance();
    Player * p = game->getPlayerByTurn();
    return p->king->layoutPosition;
}

int King::movePermitted(Position newpos, BoardState * bs, bool useCheckCondition)
{
    Position * pos = bs->getPositionByType(KING);
    if(!pos)
        return 0;

    if( (newpos.row != pos->row) || (newpos.column != pos->column) ) // not the same spot as it is currently
    {
        int colOffset = abs(pos->column - newpos.column);
        int rowOffset = abs(pos->row - newpos.row);
        if( colOffset <= 1 && rowOffset <=1  )
        {
            ChessPiece * cp = bs->board[newpos.row][newpos.column];
            if(useCheckCondition && King::isCheck(newpos,bs))
                return 0;
            if(cp)
            {
                if(cp->colour != bs->board[pos->row][pos->column]->colour) // not the same team
                    return 2;
                else
                    return 0;
            }
            return 1;
        }
    }
    return 0;
}

// TODO Check if the king is in check
int King::movePermitted(Position newpos)
{
    Position pos = this->getPosition();
    if( (newpos.row != pos.row) || (newpos.column != pos.column) ) // not the same spot as it is currently
    {
        int colOffset = abs(pos.column - newpos.column);
        int rowOffset = abs(pos.row - newpos.row);
        if( colOffset <= 1 && rowOffset <=1  )
        {
            PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget());
            ChessPiece * cp = (ChessPiece*)pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget();
            if(King::isCheck(newpos))
                return 0;
            if(!newPosPiece) // Not a placeholder
            {
                if(cp->colour != this->colour) // not the same team
                    return 2;
                else
                    return 0;
            }
            return 1;
        }
    }
    return 0;
}

bool King::isCheck(Position pos,BoardState * bs)
{
    if(!bs)
    {
        BoardState tempBoardState;
        tempBoardState.clone();
        bs = &tempBoardState;
    }
    else
    {
        BoardState tempBoardState;
        tempBoardState.copy(bs);
        bs = &tempBoardState;
    }

    bs->move(KING,pos);

    if( Bishop::movePermitted(pos,bs) || Pawn::movePermitted(pos, bs) || King::movePermitted(pos, bs, false) ) // is the position of the king a permitted move for the opponent
        return true;
    return false;
}
