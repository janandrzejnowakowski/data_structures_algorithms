//
// Created by noj on 15.11.20.
//

#include <vector>
#include "LinkedList.h"

Node::Node() : value(0), next(nullptr) {}
Node::Node(int val) : value(val), next(nullptr) {}
Node::Node(int val, Node* node) : value(val), next(node) {}

Node::Node(std::vector<int> vec)
{
    value = vec.empty() ? 0 : vec[0];
    Node* current = this;
    for (unsigned i = 1; i < vec.size(); ++i)
    {
        current->setNext(new Node(vec[i]));
        current = current->getNext();
    }
}

Node::~Node()
{
    delete next;
}

int Node::getValue()
{
    return value;
}

void Node::setValue(int val)
{
    value = val;
}

Node* Node::getNext()
{
    return next;
}

void Node::setNext(Node* node)
{
    next = node;
}

std::string Node::getString()
{
    std::string ret = std::to_string(value);
    Node* current = getNext();
    while (current)
    {
        ret += " -> " + std::to_string(current->getValue());
        current = current->getNext();
    }
    return ret;
}