//
// Created by noj on 22.11.20.
//
// DoublyLinkedList.h

#ifndef DATA_STRUCTURES_ALGORITHMS_DOUBLYLINKEDLIST_H
#define DATA_STRUCTURES_ALGORITHMS_DOUBLYLINKEDLIST_H

#include <string>

template <class T>
class DLLNode {
    T value;
    DLLNode<T>* prev;
    DLLNode<T>* next;

public:
    DLLNode();
    explicit DLLNode(T);
    DLLNode(T, DLLNode<T>*);
    explicit DLLNode(std::vector<T>);
    ~DLLNode();
    T getValue();
    void setValue(T);
    DLLNode<T>* getNext();
    DLLNode<T>* getPrev();
    void setNext(DLLNode<T>*);
    void setPrev(DLLNode<T>*);
    std::string getString(const std::string& = " <-> ");
};

#include "data_structures/DoublyLinkedList.tpp"

#endif //DATA_STRUCTURES_ALGORITHMS_DOUBLYLINKEDLIST_H
