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

template <class T>
std::string BinaryTree<T>::getString()
{
    std::string l = getLeft() ? getLeft()->getString() : "";
    std::string r = getRight() ? getRight()->getString() : "";
    std::string val;
    if constexpr(std::is_same_v<T, std::string>)
        val = value;
    else
        val = std::to_string(value);
    return l + " " + val + r;
}