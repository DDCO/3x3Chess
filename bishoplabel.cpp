#include "bishoplabel.h"

BishopLabel::BishopLabel(Colour c) : DragableLabel(0,0), Bishop(c)
{
    if(c == BLACK)
    {
        this->loadImage(":images/black_bishop_s.png");
        this->layoutPosition.row = 0;
        this->layoutPosition.column = 0;
    }
    else
    {
        this->loadImage(":images/white_bishop_s.png");
        this->layoutPosition.row = 2;
        this->layoutPosition.column = 0;
    }
}
