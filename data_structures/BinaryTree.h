//
// Created by noj on 22.11.20.
//

#ifndef DATA_STRUCTURES_ALGORITHMS_BINARYTREE_H
#define DATA_STRUCTURES_ALGORITHMS_BINARYTREE_H

template <class T>
class BinaryTree {
private:
    T value;
    BinaryTree<T>* left;
    BinaryTree<T>* right;
public:
    explicit BinaryTree(T);
    ~BinaryTree();
    void setLeft(T);
    void setRight(T);
    T getValue();
    void setValue(T);
    BinaryTree<T>* getLeft();
    BinaryTree<T>* getRight();
    std::string getString();

};

#include "BinaryTree.tpp"

#endif //DATA_STRUCTURES_ALGORITHMS_BINARYTREE_H
