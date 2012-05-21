#ifndef KINGLABEL_H
#define KINGLABEL_H

#include "dragablelabel.h"
#include "king.h"
#include "global.h"

class KingLabel : public DragableLabel, public King
{
public:
    KingLabel(Colour);
};

#endif // KINGLABEL_H
