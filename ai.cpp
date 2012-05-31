#include "ai.h"

AI::AI()
{
    this->treeRoot = NULL; // add current board to top of the tree
    this->depth = 5; // tree depth
}

void AI::setupTree()
{
    BoardStateNode * b = new BoardStateNode();
    b->clone(); // Clone current board
    this->treeRoot = b; // add current board to top of the tree
    this->getAvailableMoves(this->treeRoot);
}

void AI::MaxMove()
{
    int index = 0, max = 0;
    for(int i = 0; i < this->treeRoot->childNodeList.size(); i++)
    {
        int points = this->EvaluateMove(this->treeRoot->childNodeList.at(i));
        if(points > max)
        {
            index = i;
            max = points;
        }
    }
    //BoardStateNode * bsn1 = (BoardStateNode*)this->treeRoot;
    BoardStateNode * bsn = (BoardStateNode*)this->treeRoot->childNodeList.at(index);

    switch(bsn->movePieceType)
    {
        case BISHOP:
            this->bishop->movePiece(bsn->movePosition);
            break;
        case PAWN:
            this->pawn->movePiece(bsn->movePosition);
            break;
        case KING:
            this->king->movePiece(bsn->movePosition);
            break;
    }
}

void AI::MinMove()
{

}

bool AI::movesAvailable()
{
    return (this->treeRoot->childNodeList.size()>=1)?true:false;
}

void AI::updateTree()
{
    Node * pHead = this->treeRoot;
    BoardState curState;
    curState.clone(); //clone layout
    for(int i = 0; i < this->treeRoot->childNodeList.size(); i++)
    {
        BoardState * pbs = (BoardState*)((BoardStateNode*)this->treeRoot->childNodeList.at(i));
        if(curState == *pbs)
        {
            this->treeRoot = this->treeRoot->childNodeList.at(i);
            //delete parent + siblings
            this->getAvailableMoves(this->treeRoot);
            return;
        }
    }
}

void AI::getAvailableMoves(Node * node, int level)
{
    if(this->depth <= level)
        return;
    if(!node->childNodeList.empty())
        this->getAvailableMoves(node->childNodeList.at(0),++level);

    Node * siblings = node;
    do
    {
        for(int row = 0; row < 3; row++)
        {
            for(int column = 0; column < 3; column++)
            {
                BoardStateNode * bsn =(BoardStateNode*)siblings;

                Position newpos;
                newpos.row = row;
                newpos.column = column;
                if(Bishop::movePermitted(newpos,(BoardState*)bsn))
                {
                    BoardStateNode * newNode = new BoardStateNode();
                    newNode->copy((BoardState*)bsn);
                    newNode->move(BISHOP,newpos);
                    bsn->addNode(newNode);
                }

                if(Pawn::movePermitted(newpos,(BoardState*)bsn))
                {
                    BoardStateNode * newNode = new BoardStateNode();
                    newNode->copy((BoardState*)bsn);
                    newNode->move(PAWN,newpos);
                    bsn->addNode(newNode);
                }
                if(King::movePermitted(newpos,(BoardState*)bsn))
                {
                    BoardStateNode * newNode = new BoardStateNode();
                    newNode->copy((BoardState*)bsn);
                    newNode->move(KING,newpos);
                    bsn->addNode(newNode);
                }
                //check if pieces can move to this position
                //if they can add the new boardstatenode to tree as a child to node
            }
        }
        if(!siblings->childNodeList.empty())
            this->getAvailableMoves(siblings->childNodeList.at(0),++level);
    }while(siblings = siblings->getNextSibling());

    //this->getAvailableMoves(node->childNodeList.at(0),++level);
}

int AI::EvaluateMove(Node * node)
{
    Colour colour = BLACK;
    if( ( ((BoardStateNode*)node)->turnCount % 2) == 0 )
        colour = WHITE;

    return ((BoardStateNode*)node)->childrenCount() + ((BoardStateNode*)node)->countTotalPieces(colour);
}

AI::~AI()
{
    //delete this->treeRoot;
}
