//
// Created by noj on 22.11.20.
//
// testBinaryTree.cpp

#include <gtest/gtest.h>
#include <iostream>
#include "data_structures/BinaryTree.h"

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

int main(int argc, char **argv)
{
    std::cout << "------------------------------ Starting Binary Tree tests -----------------------------" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
