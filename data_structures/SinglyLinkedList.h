//
// Created by noj on 15.11.20.
//
// LinkedList.h

#ifndef DATA_STRUCTURES_ALGORITHMS_SINGLYLINKEDLIST_H
#define DATA_STRUCTURES_ALGORITHMS_SINGLYLINKEDLIST_H

#include <vector>
#include <string>

template <class T>
class SLLNode {
    T value;
    SLLNode<T>* next;
public:
    SLLNode();
    explicit SLLNode(T);
    explicit SLLNode(std::vector<T>);
    ~SLLNode();
    T getValue();
    void setValue(T);
    SLLNode<T>* getNext();
    void setNext(SLLNode<T>*);
    std::string getString(const std::string& = " -> ");
};

#include "data_structures/SinglyLinkedList.tpp"

#endif //DATA_STRUCTURES_ALGORITHMS_SINGLYLINKEDLIST_H
