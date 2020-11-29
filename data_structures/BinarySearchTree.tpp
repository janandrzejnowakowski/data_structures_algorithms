//
// Created by noj on 29.11.20.
//

#include "BinarySearchTree.h"

template <class T>
BST<T>::BST(T val)
{
    value = val;
    instances = 1;
    left = right = nullptr;
}

template <class T>
BST<T>::BST(std::vector<T> vec)
{
    for (T each : vec)
    {
        BST* current = this;
        while (true)
        {
            if (!current->instances || current->value == each)
            {
                current->value = each;
                current->left = current->right = nullptr;
                ++current->instances;
                break;
            } else if (current->value > each)
            {
                if (current->left)
                    current = current->left;
                else {
                    current->left = new BST(each);
                    break;
                }
            } else {
                if (current->right)
                    current = current->right;
                else {
                    current->right = new BST(each);
                    break;
                }
            }
        }
    }
}

template <class T>
BST<T>::~BST()
{
    delete left;
    delete right;
}

template <class T>
BST<T>* BST<T>::find(T val)
{
    if (value == val)
        return this;
    if (value > val && left)
    {
        return left->find(val);
    } else if (value < val && right)
    {
        return right->find(val);
    } else
    {
        return nullptr;
    }
}

template <class T>
bool BST<T>::has(T val)
{
    BST* res = find(val);
    return res != nullptr;
}

template <class T>
void BST<T>::insert(T val)
{
    BST* current = this;
    while (true)
    {
        if (current->value == val)
        {
            ++current->instances;
            return;
        }
        if (current->value > val)
        {
            if (current->left)
            {
                current->left->insert(val);
                return;
            }
            else {
                current->left = new BST(val);
                return;
            }
        }
        else
        {
            if (current->right)
            {
                current->right->insert(val);
                return;
            }
            else {
                current->right = new BST(val);
                return;
            }
        }
    }
}
