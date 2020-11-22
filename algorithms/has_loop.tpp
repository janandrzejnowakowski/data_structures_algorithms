//
// Created by noj on 20.11.20.
//
// has_loop.tpp

#include "data_structures/SinglyLinkedList.h"

template <class T>
bool hasLoop(SLLNode<T>* head) {
    if (!head || !head->getNext())
        return false;
    SLLNode<T>* slow = head;
    SLLNode<T>* fast = head->getNext();
    while (true) {
        if (!fast->getNext() || !fast->getNext()->getNext())
            return false;
        if (fast == slow)
            return true;
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
}
