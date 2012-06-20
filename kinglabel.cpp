#include "kinglabel.h"

KingLabel::KingLabel(Colour c) : DragableLabel(0,0), King(c)
{
    if(c == BLACK)
    {
        this->loadImage(":images/black_king_s.png");
        this->layoutPosition.row = 0;
        this->layoutPosition.column = 2;
    }
    else
    {
        this->loadImage(":images/white_king_s.png");
        this->layoutPosition.row = 2;
        this->layoutPosition.column = 0;
    }
}
