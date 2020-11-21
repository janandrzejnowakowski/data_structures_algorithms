//
// Created by noj on 15.11.20.
//
// LinkedList.h

#ifndef DATA_STRUCTURES_ALGORITHMS_LINKEDLIST_H
#define DATA_STRUCTURES_ALGORITHMS_LINKEDLIST_H

#include <vector>
#include <string>

template <class T>
class Node {
    T value;
    Node* next;
public:
    Node();
    explicit Node(T);
    Node(T, Node<T>*);
    Node(std::vector<T>);
    ~Node();
    T getValue();
    void setValue(T);
    Node<T>* getNext();
    void setNext(Node<T>*);
    std::string getString();
};

#include "data_structures/LinkedList.tpp"

#endif //DATA_STRUCTURES_ALGORITHMS_LINKEDLIST_H
