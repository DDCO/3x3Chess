#include "pawn.h"
#include "game.h"

Pawn::Pawn(Colour c)
{
    this->colour = c;
    this->isPromotted = false;
}

Position Pawn::getPosition()
{
    Game * game = Game::getInstance();
    Player * p = game->getPlayerByTurn();
    return p->pawn->layoutPosition;
}

int Pawn::movePermitted(Position newpos, BoardState * bs)
{
    ChessPiece * cp = bs->board[newpos.row][newpos.column];
    Position * pos = bs->getPositionByType(PAWN);
    if(!pos)
        return 0;

    Colour colour = bs->board[pos->row][pos->column]->colour;

    if( ((colour == BLACK) && ((pos->row+1) == newpos.row)) || ((colour == WHITE) && ((pos->row-1) == newpos.row)) )
    {
        if((pos->column == newpos.column) && cp == NULL)
            return 1;
        if(cp && (cp->colour != colour) )
        {
            if((pos->column-1) == newpos.column)
                return 2;
            else if((pos->column+1) == newpos.column)
                return 2;
        }
    }
    return 0;
}

int Pawn::movePermitted(Position newpos)
{
    if(this->isPromotted)
    {
        BoardState tempbs;
        tempbs.clone();
        return Bishop::movePermitted(newpos,&tempbs,tempbs.getPositionByType(PAWN));
    }

    int returnVal = 0;

    ChessPiece * cp = (ChessPiece*)pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget();
    // if NULL that means the cast failed and it is not PlaceHolder Object, meaning there is a piece in this position
    PlaceHolder * newPosPiece = dynamic_cast<PlaceHolder*>(pGridLayout->itemAtPosition(newpos.row,newpos.column)->widget());
    Position pos = this->getPosition();

    if( ((this->colour == BLACK) && ((pos.row+1) == newpos.row)) || ((this->colour == WHITE) && ((pos.row-1) == newpos.row)) )
    {
        if((pos.column == newpos.column) && newPosPiece != NULL)
            returnVal = 1;
        if(newPosPiece == NULL && (cp->colour != this->colour) ) //Not a PlaceHolder and chesspiece is not the same team
        {
            if((pos.column-1) == newpos.column)
                returnVal = 2;
            else if((pos.column+1) == newpos.column)
                returnVal = 2;
        }
    }

    if( returnVal && (newpos.row % 2 == 0) )
    {
        this->isPromotted = true;
        Game * game = Game::getInstance();
        if(this->colour == BLACK)
            game->p2->pawn->loadImage(":images/black_bishop_s.png");
        else
            game->p1->pawn->loadImage(":images/white_bishop_s.png");
    }

    return returnVal;
}
