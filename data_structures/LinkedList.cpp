//
// Created by noj on 15.11.20.
//

#include "LinkedList.h"

Node::Node() : value(0), next(nullptr) {} ;
Node::Node(int val) : value(val), next(nullptr) {} ;
Node::Node(int val, Node* node) : value(val), next(node) {};

Node::~Node()
{
    delete next;
};

int Node::getValue()
{
    return value;
};

void Node::setValue(int val)
{
    value = val;
};

Node* Node::getNext()
{
    return next;
};

void Node::setNext(Node* node)
{
    next = node;
};