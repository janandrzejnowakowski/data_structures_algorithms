//
// Created by noj on 15.11.20.
//

#ifndef DATA_STRUCTURES_ALGORITHMS_LINKEDLIST_H
#define DATA_STRUCTURES_ALGORITHMS_LINKEDLIST_H

class Node {
    int value;
    Node* next;
public:
    Node();
    Node(int);
    Node(int, Node*);
    ~Node();
    int getValue();
    void setValue(int);
    Node* getNext();
    void setNext(Node*);
};

#endif //DATA_STRUCTURES_ALGORITHMS_LINKEDLIST_H
