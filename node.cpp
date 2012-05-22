#include "node.h"

Node::Node()
{
    this->parentNode = __null;
    this->nextSibling = __null;
    this->previousSibling = __null;
}

void Node::addNode(Node * node)
{
    if(this->childNodeList.size() > 0)
    {
        Node * prevNode = this->childNodeList.at(this->childNodeList.size()-1);
        prevNode->nextSibling = node;
        node->previousSibling = prevNode;
    }
    node->setParent(this);
    this->childNodeList.push_back(node);
}

Node * Node::getParent()
{
    return this->parentNode;
}

Node * Node::getNextSibling()
{
    return this->nextSibling;
}

Node * Node::getPreviousSibling()
{
    return this->previousSibling;
}

void Node::setParent(Node* node)
{
    this->parentNode = node;
}

void Node::setNextSibling(Node* node)
{
    this->nextSibling = node;
}

void Node::setPreviousSibling(Node* node)
{
    this->previousSibling = node;
}

int Node::childrenCount()
{
    int count = 0;
    Node * child = this->childNodeList.at(0);
    while(child)
    {
        if(!child->childNodeList.empty())
            count+= child->childrenCount();
        child = child->getNextSibling();
        count++;
    }
    return count;
}

Node::~Node()
{
    for(int i = 0; i < this->childNodeList.size(); i++)
        delete this->childNodeList.at(i);
    this->childNodeList.clear();
}
