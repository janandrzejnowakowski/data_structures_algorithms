//
// Created by noj on 22.11.20.
//
// Stack.h

#include "Stack.h"

template <class T>
Stack<T>::Stack(std::vector<T> vec)
{
    head = new DLLNode<T>(vec);
    tail = head;
    while (tail->getNext())
        tail = tail->getNext();
    size = vec.size();
}

template <class T>
Stack<T>::~Stack()
{
    delete head;
}

template <class T>
T Stack<T>::peek()
{
    return empty() ? static_cast<T>(0) : tail->getValue();
}

template <class T>
T Stack<T>::pop()
{
    if (empty())
        return static_cast<T>(0);
    --size;
    T ret = tail->getValue();
    DLLNode<T>* new_tail = tail->getPrev();
    if (new_tail) {
        new_tail->setNext(nullptr);
        delete tail;
    }
    tail = new_tail;
    return ret;
}

template <class T>
bool Stack<T>::empty()
{
    return size == 0;
}
template <class T>
void Stack<T>::push(T val)
{
    auto* new_node = new DLLNode<T>(val);
    ++size;
    if (size == 1) {
        delete head;
        head = tail = new_node;
        return;
    }
    tail->setNext(new_node);
    new_node->setPrev(tail);
    tail = new_node;
}