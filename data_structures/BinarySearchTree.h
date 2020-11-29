//
// Created by noj on 29.11.20.
//

#ifndef DATA_STRUCTURES_ALGORITHMS_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_ALGORITHMS_BINARYSEARCHTREE_H

#include <vector>

template <class T>
class BST {
    T value;
    unsigned instances = 0;
    BST* left;
    BST* right;
    BST* find(T val);
public:
    BST(T);
    BST(std::vector<T>);
    ~BST();
    void insert(T);
    bool has(T);
};

#include "data_structures/BinarySearchTree.tpp"

#endif //DATA_STRUCTURES_ALGORITHMS_BINARYSEARCHTREE_H
