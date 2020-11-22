//
// Created by noj on 22.11.20.
//
// DoublyLinkedList.tpp

#include <vector>
#include "DoublyLinkedList.h"

template <class T>
DLLNode<T>::DLLNode() : value(0), prev(nullptr), next(nullptr) {}

template <class T>
DLLNode<T>::DLLNode(T val) : value(val), prev(nullptr), next(nullptr) {}

template <class T>
DLLNode<T>::DLLNode(T val, DLLNode<T>* prev) : value(val), prev(prev), next(nullptr) {}

template <class T>
DLLNode<T>::DLLNode(std::vector<T> vec)
{
    DLLNode<T>* current = this;
    current->value = vec.empty() ? 0 : vec[0];
    current->setNext(nullptr);
    current->setPrev(nullptr);
    for (unsigned i = 1; i < vec.size(); ++i)
    {
        current->setNext(new DLLNode<T>(vec[i], current));
        current = current->getNext();
    }
}

template <class T>
DLLNode<T>::~DLLNode()
{
    delete next;
}

template <class T>
T DLLNode<T>::getValue()
{
    return value;
}

template <class T>
void DLLNode<T>::setValue(T val)
{
    value = val;
}

template <class T>
DLLNode<T>* DLLNode<T>::getNext()
{
    return next;
}

template <class T>
DLLNode<T>* DLLNode<T>::getPrev()
{
    return prev;
}

template <class T>
void DLLNode<T>::setNext(DLLNode<T>* node)
{
    next = node;
}

template <class T>
void DLLNode<T>::setPrev(DLLNode<T>* node)
{
    prev = node;
}

template <class T>
std::string DLLNode<T>::getString(const std::string& connector)
{
    std::string ret = std::to_string(value);
    DLLNode<T>* current = getNext();
    while (current)
    {
        ret += connector + std::to_string(current->getValue());
        current = current->getNext();
    }
    return ret;
}