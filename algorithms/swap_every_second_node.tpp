//
// Created by noj on 15.11.20.
//
// swap_every_second_node.cpp

#include <iostream>
#include "data_structures/LinkedList.h"

template <class T>
Node<T>* swapEverySecondNode(Node<T>* head)
{
    if (!head || !head->getNext())
        return head;
    Node<T>* new_head = head->getNext();
    Node<T>* current = head;
    Node<T> *tail, *temp;
    unsigned node_number = 0;
    while (current) {
        temp = current->getNext();
        if (node_number % 2) {
            current->setNext(tail);
        } else {
            tail = current;
            if (!temp)
                current->setNext(nullptr);
            else if (current->getNext() && current->getNext()->getNext() && current->getNext()->getNext()->getNext())
                current->setNext(current->getNext()->getNext()->getNext());
            else
                current->setNext(current->getNext()->getNext());
        }
        current = temp;
        node_number++;
    }
    return new_head;
}

template <class T>
void swapEverySecondNodeByValue(Node<T>* head)
{
    if (!head || !head->getNext())
        return;
    Node<T>* current = head;
    while (current && current->getNext()) {
        T temp = current->getValue();
        current->setValue(current->getNext()->getValue());
        current->getNext()->setValue(temp);
        current = current->getNext()->getNext();
    }
}