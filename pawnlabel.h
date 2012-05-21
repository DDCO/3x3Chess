#ifndef PAWNLABEL_H
#define PAWNLABEL_H

#include "dragablelabel.h"
#include "pawn.h"
#include "global.h"

class PawnLabel : public DragableLabel, public Pawn
{
public:
    PawnLabel(Colour);
};

#endif // PAWNLABEL_H
