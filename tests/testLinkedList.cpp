//
// Created by noj on 20.11.20.
//
// testLinkedList.cpp

#include "data_structures/LinkedList.h"
#include "algorithms/swap_every_second_node.h"
#include <gtest/gtest.h>

TEST(LinkedListTest, ConstructorTest) {
    std::vector<int> all_nodes = {};
    Node* node = new Node(all_nodes);
    EXPECT_TRUE(node->getValue() == 0);
    EXPECT_TRUE(node->getNext() == nullptr);

    all_nodes = {1, 2, 3, 4, 5};
    node = new Node(all_nodes);
    for (int each : all_nodes) {
        EXPECT_TRUE(each == node->getValue());
        node = node->getNext();
    }
    EXPECT_TRUE(node == nullptr);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}