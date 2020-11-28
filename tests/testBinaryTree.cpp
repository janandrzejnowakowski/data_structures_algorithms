//
// Created by noj on 22.11.20.
//
// testBinaryTree.cpp

#include <gtest/gtest.h>
#include <iostream>
#include "data_structures/BinaryTree.h"
#include "data_structures/EquationBinaryTree.h"
#include "algorithms/binary_tree_algorithms.h"

TEST(BinaryTree, Constructor)
{
    auto* bt = new BinaryTree<int>(5);
    bt->setLeft(7);
    bt->setRight(9);
    EXPECT_TRUE(bt->getValue() == 5);
    EXPECT_TRUE(bt->getLeft()->getValue() == 7);
    EXPECT_TRUE(bt->getRight()->getValue() == 9);
    bt->setRight(19);
    EXPECT_TRUE(bt->getRight()->getValue() == 19);
    delete bt;
}

TEST(BinaryTree, GetString)
{
    auto* bt = new BinaryTree<int>(2);
    bt->setLeft(1);
    bt->setRight(3);
    EXPECT_EQ(bt->getString(), " 1 2 3");
    bt->getRight()->setRight(4);
    EXPECT_EQ(bt->getString(), " 1 2 3 4");
    bt->getLeft()->setRight(5);
    EXPECT_EQ(bt->getString(), " 1 5 2 3 4");
    bt->getLeft()->setLeft(6);
    EXPECT_EQ(bt->getString(), " 6 1 5 2 3 4");
    bt->getRight()->setLeft(7);
    EXPECT_EQ(bt->getString(), " 6 1 5 2 7 3 4");
    delete bt;
}

TEST(BinaryTree, ReverseBinaryTree)
{
    auto* bt = new BinaryTree<int>(2);
    bt->setLeft(1);
    bt->setRight(3);
    bt->getRight()->setRight(4);
    bt->getLeft()->setRight(5);
    bt->getLeft()->setLeft(6);
    bt->getRight()->setLeft(7);
    EXPECT_EQ(bt->getString(), " 6 1 5 2 7 3 4");
    reverseBinaryTree(bt);
    EXPECT_EQ(bt->getString(), " 4 3 7 2 5 1 6");
    delete bt;
}

TEST(EquationBinaryTree, GetString)
{
    auto* bt = new EBT({"+", "-", "*"}, {1, 2, 3, 4});
    EXPECT_EQ(bt->getString(false), "((1.000000 - 2.000000) + (3.000000 * 4.000000))");
    EXPECT_EQ(bt->getString(true), "((1.000000 - 2.000000) + (3.000000 * 4.000000)) = 11.000000");
    EXPECT_EQ(bt->calculateValue(), 11);
    delete bt;
    auto* bt2 = new EBT({"+", "-", "*", "+", "-", "*", "/"}, {13, 7, 3, 4, 11, 2, 16, 8});
    EXPECT_EQ(bt2->getString(true), "(((13.000000 + 7.000000) - (3.000000 - 4.000000)) + ((11.000000 * 2.000000) * (16.000000 / 8.000000))) = 65.000000");
    EXPECT_EQ(bt2->calculateValue(), 65);
    delete bt2;
}

int main(int argc, char **argv)
{
    std::cout << "------------------------------ Starting Binary Tree tests -----------------------------" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
