//
// Created by noj on 15.11.20.
//
// LinkedList.cpp

#include <vector>
#include "LinkedList.h"

template <class T>
Node<T>::Node() : value(0), next(nullptr) {}
template <class T>
Node<T>::Node(T val) : value(val), next(nullptr) {}
template <class T>
Node<T>::Node(T val, Node<T>* node) : value(val), next(node) {}

template <class T>
Node<T>::Node(std::vector<T> vec)
{
    Node<T>* current = this;
    current->value = vec.empty() ? 0 : vec[0];
    current->setNext(nullptr);
    for (unsigned i = 1; i < vec.size(); ++i)
    {
        current->setNext(new Node<T>(vec[i]));
        current = current->getNext();
    }
}

template <class T>
Node<T>::~Node()
{
    delete next;
}

template <class T>
T Node<T>::getValue()
{
    return value;
}

template <class T>
void Node<T>::setValue(T val)
{
    value = val;
}

template <class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setNext(Node* node)
{
    next = node;
}

template <class T>
std::string Node<T>::getString()
{
    std::string ret = std::to_string(value);
    Node<T>* current = getNext();
    while (current)
    {
        ret += " -> " + std::to_string(current->getValue());
        current = current->getNext();
    }
    return ret;
}