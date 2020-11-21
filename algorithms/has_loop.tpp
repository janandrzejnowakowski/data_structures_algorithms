//
// Created by noj on 20.11.20.
//
// has_loop.tpp

#include "data_structures/LinkedList.h"

template <class T>
bool hasLoop(Node<T>* head) {
    if (!head || !head->getNext())
        return false;
    Node<T>* slow = head;
    Node<T>* fast = head->getNext();
    while (true) {
        if (!fast->getNext() || !fast->getNext()->getNext())
            return false;
        if (fast == slow)
            return true;
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
}
