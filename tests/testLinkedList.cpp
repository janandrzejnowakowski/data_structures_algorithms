//
// Created by noj on 20.11.20.
//
// testSinglyLinkedList.cpp

#include <gtest/gtest.h>
#include <iostream>
#include "data_structures/SinglyLinkedList.h"
#include "data_structures/DoublyLinkedList.h"
#include "algorithms/linked_list_algorithms.h"

TEST(SinglyLinkedListTest, ConstructorTest)
{
    std::vector<int> all_nodes = {};
    auto* node = new SLLNode<int>(all_nodes);
    EXPECT_TRUE(node->getValue() == 0);
    EXPECT_TRUE(node->getNext() == nullptr);
    delete node;

    all_nodes = {1, 2, 3, 4, 5};
    node = new SLLNode<int>(all_nodes);
    SLLNode<int>* current = node;
    for (int each : all_nodes) {
        EXPECT_TRUE(each == current->getValue());
        current = current->getNext();
    }
    EXPECT_TRUE(current == nullptr);
    delete node;
}

TEST(SinglyLinkedListTest, GetStringTest)
{
    std::vector<int> all_nodes = {};
    auto* node = new SLLNode<int>(all_nodes);
    EXPECT_EQ(node->getString(), "0");
    delete node;

    all_nodes = {1, 2, 3, 4, 5};
    node = new SLLNode<int>(all_nodes);
    EXPECT_EQ(node->getString(), "1 -> 2 -> 3 -> 4 -> 5");
    delete node;
}


TEST(SinglyLinkedListTest, SwapEverySecondTest)
{
    std::vector<int> all_nodes = {};
    auto* node = new SLLNode<int>(all_nodes);
    node = swapEverySecondSLLNode(node);
    EXPECT_EQ(node->getString(), "0");
    swapEverySecondSLLNodeByValue(node);
    EXPECT_EQ(node->getString(), "0");
    delete node;

    all_nodes = {1, 2, 3, 4};
    node = new SLLNode<int>(all_nodes);
    swapEverySecondSLLNodeByValue(node);
    EXPECT_EQ(node->getString(), "2 -> 1 -> 4 -> 3");
    swapEverySecondSLLNodeByValue(node);
    EXPECT_EQ(node->getString(), "1 -> 2 -> 3 -> 4");
    node = swapEverySecondSLLNode(node);
    EXPECT_EQ(node->getString(), "2 -> 1 -> 4 -> 3");
    delete node;

    std::vector<double> all_nodes_double = {1.2, 2.3, 3.5, 4.6, 5.9};
    auto* node_double = new SLLNode<double>(all_nodes_double);
    swapEverySecondSLLNodeByValue(node_double);
    EXPECT_EQ(node_double->getString(), "2.300000 -> 1.200000 -> 4.600000 -> 3.500000 -> 5.900000");
    swapEverySecondSLLNodeByValue(node_double);
    EXPECT_EQ(node_double->getString(), "1.200000 -> 2.300000 -> 3.500000 -> 4.600000 -> 5.900000");
    node_double = swapEverySecondSLLNode(node_double);
    EXPECT_EQ(node_double->getString(), "2.300000 -> 1.200000 -> 4.600000 -> 3.500000 -> 5.900000");
    delete node_double;
}

TEST(SinglyLinkedList, HasLoop)
{
    auto* node = new SLLNode<int>();
    EXPECT_FALSE(hasLoop(node));
    delete node;

    std::vector<int> all_nodes = {1, 2, 3};
    node = new SLLNode<int>(all_nodes);
    EXPECT_FALSE(hasLoop(node));
    all_nodes = {1, 2, 3};
    delete node;

    node = new SLLNode<int>(all_nodes);
    EXPECT_FALSE(hasLoop(node));
    node->getNext()->getNext()->setNext(node);
    EXPECT_TRUE(hasLoop(node));
    node->getNext()->getNext()->setNext(nullptr);
    delete node;

    node = new SLLNode<int>(all_nodes);
    node->getNext()->getNext()->setNext(node->getNext());
    EXPECT_TRUE(hasLoop(node));
    node->getNext()->getNext()->setNext(nullptr);
    delete node;
}

TEST(DoublyLinkedListTest, ConstructorTest)
{
    std::vector<int> all_nodes = {};
    auto* node = new DLLNode<int>(all_nodes);
    EXPECT_TRUE(node->getValue() == 0);
    EXPECT_TRUE(node->getNext() == nullptr);
    EXPECT_TRUE(node->getPrev() == nullptr);
    delete node;

    all_nodes = {1, 2, 3, 4, 5};
    node = new DLLNode<int>(all_nodes);
    DLLNode<int>* current = node;
    for (int each : all_nodes) {
        EXPECT_TRUE(each == current->getValue());
        current = current->getNext();
    }
    EXPECT_TRUE(current == nullptr);

    current = node->getNext()->getNext()->getNext();
    EXPECT_TRUE(current->getValue() == 4);
    current = current->getPrev()->getPrev()->getNext();
    EXPECT_TRUE(current->getValue() == 3);
    delete node;
}

TEST(DoublyLinkedListTest, GetStringTest)
{
    std::vector<int> all_nodes = {};
    auto* node = new DLLNode<int>(all_nodes);
    EXPECT_EQ(node->getString(), "0");
    delete node;

    all_nodes = {1, 2, 3, 4, 5};
    node = new DLLNode<int>(all_nodes);
    EXPECT_EQ(node->getString(), "1 <-> 2 <-> 3 <-> 4 <-> 5");
    delete node;
}


int main(int argc, char **argv)
{
    std::cout << "------------------------------ Starting SinglyLinkedList tests -----------------------------" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
