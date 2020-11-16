//
// Created by noj on 15.11.20.
//

#include <iostream>
#include "data_structures/LinkedList.h"

Node* swapEverySecondNode(Node* head)
{
    if (!head || !head->getNext())
        return head;
    Node* new_head = head->getNext();
    Node* current = head;
    Node *tail, *temp;
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

int main() {
    std::vector<int> all_nodes = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* node = new Node(all_nodes);
    std::cout << node->getString() << std::endl;
    node = swapEverySecondNode(node);
    std::cout << node->getString() << std::endl;
    return 0;
}