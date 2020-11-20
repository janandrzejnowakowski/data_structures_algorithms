//
// Created by noj on 20.11.20.
//
// testLinkedList.cpp

#include "data_structures/LinkedList.h"
#include "algorithms/linked_list_algorithms.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(LinkedList, Constructor) {
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

TEST(LinkedList, GetString) {
    std::vector<int> all_nodes = {};
    Node* node = new Node(all_nodes);
    EXPECT_EQ(node->getString(), "0");
    all_nodes = {1, 2, 3, 4, 5};
    node = new Node(all_nodes);
    EXPECT_EQ(node->getString(), "1 -> 2 -> 3 -> 4 -> 5");
}


TEST(LinkedList, SwapEverySecond) {
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


TEST(LinkedList, HasLoop) {
    EXPECT_FALSE(hasLoop(nullptr));
    std::vector<int> all_nodes = {};
    Node* node = new Node(all_nodes);
    EXPECT_FALSE(hasLoop(node));
    all_nodes = {1, 2, 3};
    node = new Node(all_nodes);
    EXPECT_FALSE(hasLoop(node));
    node->getNext()->getNext()->setNext(node);
    EXPECT_TRUE(hasLoop(node));
    node = new Node(all_nodes);
    node->getNext()->getNext()->setNext(node->getNext());
    EXPECT_TRUE(hasLoop(node));

}

int main(int argc, char **argv) {
    std::cout << "------------------------------ Starting LinkedList tests -----------------------------" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}