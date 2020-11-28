//
// Created by noj on 28.11.20.
//

#include <iostream>

template <class T>
void reverseBinaryTree(BinaryTree<T>* tree)
{
    if (!tree)
        return;
    reverseBinaryTree(tree->getLeft());
    reverseBinaryTree(tree->getRight());
    BinaryTree<T>* temp = tree->getLeft();
    tree->setLeft(tree->getRight());
    tree->setRight(temp);
}