#ifndef BISHOPLABEL_H
#define BISHOPLABEL_H

#include "dragablelabel.h"
#include "bishop.h"
#include "global.h"

class BishopLabel : public DragableLabel, public Bishop
{
public:
    BishopLabel(Colour);
};

#endif // BISHOPLABEL_H
