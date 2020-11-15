//
// Created by noj on 15.11.20.
//

#include <iostream>
#include "data_structures/LinkedList.h"

void swapEverySecondNode(Node* head)
{
    if (!head || !head->getNext())
        return;
    // TODO

}

int main() {
    std::vector<int> all_nodes = {1, 2, 3, 4};//{1, 2, 3, 4, 5, 6, 7, 8};
    Node* node = new Node(all_nodes);
    std::cout << node->getString() << std::endl;
    swapEverySecondNode(node);
    std::cout << node->getString() << std::endl;
    return 0;
}