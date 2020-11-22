//
// Created by noj on 22.11.20.
//

#include "BinaryTree.h"

template <class T>
BinaryTree<T>::BinaryTree(T val) : value(val), left(nullptr), right(nullptr) {}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    delete left;
    delete right;
}

template <class T>
void BinaryTree<T>::setLeft(T val)
{
    if (left)
        left->setValue(val);
    else
        left = new BinaryTree<T>(val);
}

template <class T>
void BinaryTree<T>::setRight(T val)
{
    if (right)
        right->setValue(val);
    else
        right = new BinaryTree<T>(val);
}

template <class T>
T BinaryTree<T>::getValue()
{
    return value;
}

template <class T>
void BinaryTree<T>::setValue(T val)
{
    value = val;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::getLeft()
{
    return left;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::getRight()
{
    return right;
}

//template <class T>
//std::string BinaryTree<T>::getInOrderString(std::string& current)
//{
//
//}