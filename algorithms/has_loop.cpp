//
// Created by noj on 20.11.20.
//

#include "data_structures/LinkedList.h"

bool hasLoop(Node* head) {
    if (!head || !head->getNext())
        return false;
    Node* slow = head;
    Node* fast = head->getNext();
    while (true) {
        if (!fast->getNext() || !fast->getNext()->getNext())
            return false;
        if (fast == slow)
            return true;
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
}
