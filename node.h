#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
public:
    Node();
    ~Node();
    void addNode(Node*);
    Node * getParent();
    Node * getNextSibling();
    Node * getPreviousSibling();
    void setParent(Node*);
    void setNextSibling(Node*);
    void setPreviousSibling(Node*);
    int childrenCount();
    std::vector<Node*> childNodeList;

private:
    Node * parentNode;
    Node * nextSibling;
    Node * previousSibling;
};

#endif // NODE_H
