#ifndef AI_H
#define AI_H

#include "player.h"
#include "boardstate.h"

class AI : public Player
{
public:
    AI();
    ~AI();
    void MaxMove();
    void MinMove();
    void getAvailableMoves(Node * node, int level = 0);
    bool movesAvailable();
    int EvaluateMove(Node*);
    void updateTree();
    void setupTree();
    int getType() {return CPU;}
private:
    Node * firstNode;
    Node * treeRoot;
    int depth;
};

#endif // AI_H
