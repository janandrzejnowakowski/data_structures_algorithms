//
// Created by noj on 20.11.20.
//
// testLinkedList.cpp

#include <gtest/gtest.h>
#include <iostream>
#include "data_structures/LinkedList.h"
#include "algorithms/linked_list_algorithms.h"

TEST(LinkedListTest, ConstructorTest)
{
    std::vector<int> all_nodes = {};
    auto* node = new Node<int>(all_nodes);
    EXPECT_TRUE(node->getValue() == 0);
    EXPECT_TRUE(node->getNext() == nullptr);
    delete node;

    all_nodes = {1, 2, 3, 4, 5};
    node = new Node<int>(all_nodes);
    Node<int>* current = node;
    for (int each : all_nodes) {
        EXPECT_TRUE(each == current->getValue());
        current = current->getNext();
    }
    EXPECT_TRUE(current == nullptr);
    delete node;
}

TEST(LinkedListTest, GetStringTest)
{
    std::vector<int> all_nodes = {};
    auto* node = new Node<int>(all_nodes);
    EXPECT_EQ(node->getString(), "0");
    delete node;

    all_nodes = {1, 2, 3, 4, 5};
    node = new Node<int>(all_nodes);
    EXPECT_EQ(node->getString(), "1 -> 2 -> 3 -> 4 -> 5");
    delete node;
}


TEST(LinkedListTest, SwapEverySecondTest)
{
    std::vector<int> all_nodes = {};
    auto* node = new Node<int>(all_nodes);
    node = swapEverySecondNode(node);
    EXPECT_EQ(node->getString(), "0");
    swapEverySecondNodeByValue(node);
    EXPECT_EQ(node->getString(), "0");
    delete node;

    all_nodes = {1, 2, 3, 4};
    node = new Node<int>(all_nodes);
    swapEverySecondNodeByValue(node);
    EXPECT_EQ(node->getString(), "2 -> 1 -> 4 -> 3");
    swapEverySecondNodeByValue(node);
    EXPECT_EQ(node->getString(), "1 -> 2 -> 3 -> 4");
    node = swapEverySecondNode(node);
    EXPECT_EQ(node->getString(), "2 -> 1 -> 4 -> 3");
    delete node;

    std::vector<double> all_nodes_double = {1.2, 2.3, 3.5, 4.6, 5.9};
    auto* node_double = new Node<double>(all_nodes_double);
    swapEverySecondNodeByValue(node_double);
    EXPECT_EQ(node_double->getString(), "2.300000 -> 1.200000 -> 4.600000 -> 3.500000 -> 5.900000");
    swapEverySecondNodeByValue(node_double);
    EXPECT_EQ(node_double->getString(), "1.200000 -> 2.300000 -> 3.500000 -> 4.600000 -> 5.900000");
    node_double = swapEverySecondNode(node_double);
    EXPECT_EQ(node_double->getString(), "2.300000 -> 1.200000 -> 4.600000 -> 3.500000 -> 5.900000");
    delete node_double;
}


TEST(LinkedList, HasLoop)
{
    auto* node = new Node<int>();
    EXPECT_FALSE(hasLoop(node));
    delete node;

    std::vector<int> all_nodes = {1, 2, 3};
    node = new Node<int>(all_nodes);
    EXPECT_FALSE(hasLoop(node));
    all_nodes = {1, 2, 3};
    delete node;

    node = new Node<int>(all_nodes);
    EXPECT_FALSE(hasLoop(node));
    node->getNext()->getNext()->setNext(node);
    EXPECT_TRUE(hasLoop(node));
    node->getNext()->getNext()->setNext(nullptr);
    delete node;

    node = new Node<int>(all_nodes);
    node->getNext()->getNext()->setNext(node->getNext());
    EXPECT_TRUE(hasLoop(node));
    node->getNext()->getNext()->setNext(nullptr);
    delete node;
}

int main(int argc, char **argv)
{
    std::cout << "------------------------------ Starting LinkedList tests -----------------------------" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
