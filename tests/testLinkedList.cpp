//
// Created by noj on 20.11.20.
//
// testLinkedList.cpp

#include "data_structures/LinkedList.h"
#include "algorithms/swap_every_second_node.h"
#include <gtest/gtest.h>
#include <iostream>

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

TEST(LinkedListTest, GetStringTest) {
    std::vector<int> all_nodes = {};
    Node* node = new Node(all_nodes);
    EXPECT_EQ(node->getString(), "0");
    all_nodes = {1, 2, 3, 4, 5};
    node = new Node(all_nodes);
    EXPECT_EQ(node->getString(), "1 -> 2 -> 3 -> 4 -> 5");
}


TEST(LinkedListTest, SwapEverySecondTest) {
    std::vector<int> all_nodes = {};
    Node* node = new Node(all_nodes);
    node = swapEverySecondNode(node);
    EXPECT_EQ(node->getString(), "0");
    swapEverySecondNodeByValue(node);
    EXPECT_EQ(node->getString(), "0");

    all_nodes = {1, 2, 3, 4};
    node = new Node(all_nodes);
    swapEverySecondNodeByValue(node);
    EXPECT_EQ(node->getString(), "2 -> 1 -> 4 -> 3");
    swapEverySecondNodeByValue(node);
    EXPECT_EQ(node->getString(), "1 -> 2 -> 3 -> 4");
    node = swapEverySecondNode(node);
    EXPECT_EQ(node->getString(), "2 -> 1 -> 4 -> 3");

    all_nodes = {1, 2, 3, 4, 5};
    node = new Node(all_nodes);
    swapEverySecondNodeByValue(node);
    EXPECT_EQ(node->getString(), "2 -> 1 -> 4 -> 3 -> 5");
    swapEverySecondNodeByValue(node);
    EXPECT_EQ(node->getString(), "1 -> 2 -> 3 -> 4 -> 5");
    node = swapEverySecondNode(node);
    EXPECT_EQ(node->getString(), "2 -> 1 -> 4 -> 3 -> 5");
}

int main(int argc, char **argv) {
    std::cout << "------------------------------ Starting LinkedList tests -----------------------------" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}