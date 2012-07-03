#include "node.h"

Node::Node()
{
    this->parentNode = NULL;
    this->nextSibling = NULL;
    this->previousSibling = NULL;
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
    for(unsigned int i = 0; i < this->childNodeList.size(); i++)
    {
        count++; // count itself then children
        count+= this->childNodeList.at(i)->childrenCount();
    }
    return count;
}

Node::~Node()
{

}
