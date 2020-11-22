//
// Created by noj on 22.11.20.
//
// Stack.h

#ifndef DATA_STRUCTURES_ALGORITHMS_STACK_H
#define DATA_STRUCTURES_ALGORITHMS_STACK_H

#include "data_structures/DoublyLinkedList.h"

template <class T>
class Stack {
    DLLNode<T>* head = nullptr;
    DLLNode<T>* tail = nullptr;
    unsigned size = 0;
public:
    Stack() = default;
    Stack(std::vector<T> vec);
    ~Stack();
    T peek();
    T pop();
    bool empty();
    void push(T);
};

#include "Stack.tpp"

#endif //DATA_STRUCTURES_ALGORITHMS_STACK_H
