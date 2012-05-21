#include "pawnlabel.h"

PawnLabel::PawnLabel(Colour c) : DragableLabel(0,0), Pawn(c)
{
    if(c == BLACK)
    {
        this->loadImage(":images/black_pawn_s.png");
        this->layoutPosition.row = 0;
        this->layoutPosition.column = 1;
    }
    else
    {
        this->loadImage(":images/white_pawn_s.png");
        this->layoutPosition.row = 2;
        this->layoutPosition.column = 1;
    }
}
