//
// Created by noj on 15.11.20.
//

#ifndef DATA_STRUCTURES_ALGORITHMS_LINKEDLIST_H
#define DATA_STRUCTURES_ALGORITHMS_LINKEDLIST_H

#include <vector>
#include <string>

class Node {
    int value;
    Node* next;
public:
    Node();
    Node(int);
    Node(int, Node*);
    Node(std::vector<int>);
    ~Node();
    int getValue();
    void setValue(int);
    Node* getNext();
    void setNext(Node*);
    std::string getString();
};

#endif //DATA_STRUCTURES_ALGORITHMS_LINKEDLIST_H
