//
// Created by noj on 15.11.20.
//
// LinkedList.cpp

#include <vector>
#include "SinglyLinkedList.h"

template <class T>
SLLNode<T>::SLLNode() : value(0), next(nullptr) {}
template <class T>
SLLNode<T>::SLLNode(T val) : value(val), next(nullptr) {}
template <class T>
SLLNode<T>::SLLNode(T val, SLLNode<T>* node) : value(val), next(node) {}

template <class T>
SLLNode<T>::SLLNode(std::vector<T> vec)
{
    SLLNode<T>* current = this;
    current->value = vec.empty() ? 0 : vec[0];
    current->setNext(nullptr);
    for (unsigned i = 1; i < vec.size(); ++i)
    {
        current->setNext(new SLLNode<T>(vec[i]));
        current = current->getNext();
    }
}

template <class T>
SLLNode<T>::~SLLNode()
{
    delete next;
}

template <class T>
T SLLNode<T>::getValue()
{
    return value;
}

template <class T>
void SLLNode<T>::setValue(T val)
{
    value = val;
}

template <class T>
SLLNode<T>* SLLNode<T>::getNext()
{
    return next;
}

template <class T>
void SLLNode<T>::setNext(SLLNode* node)
{
    next = node;
}

template <class T>
std::string SLLNode<T>::getString(std::string connector)
{
    std::string ret = std::to_string(value);
    SLLNode<T>* current = getNext();
    while (current)
    {
        ret += connector + std::to_string(current->getValue());
        current = current->getNext();
    }
    return ret;
}