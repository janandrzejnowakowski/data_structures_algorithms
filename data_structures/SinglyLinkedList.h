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
    SLLNode* next;
public:
    SLLNode();
    explicit SLLNode(T);
    SLLNode(T, SLLNode<T>*);
    SLLNode(std::vector<T>);
    ~SLLNode();
    T getValue();
    void setValue(T);
    SLLNode<T>* getNext();
    void setNext(SLLNode<T>*);
    std::string getString(std::string = " -> ");
};

#include "data_structures/SinglyLinkedList.tpp"

#endif //DATA_STRUCTURES_ALGORITHMS_SINGLYLINKEDLIST_H
