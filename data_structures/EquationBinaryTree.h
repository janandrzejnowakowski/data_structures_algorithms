//
// Created by noj on 28.11.20.
//

#ifndef DATA_STRUCTURES_ALGORITHMS_EQBINARYTREE_H
#define DATA_STRUCTURES_ALGORITHMS_EQBINARYTREE_H

#include "BinaryTree.h"
#include <vector>

class EBT {
    std::string value;
    EBT* left;
    EBT* right;
public:
    EBT(const std::vector<std::string> &operations, const std::vector<double> &numbers);
    ~EBT();
    double calculateValue();
    std::string getString(bool show_result = true);
};

#include "EquationBinaryTree.cpp"

#endif //DATA_STRUCTURES_ALGORITHMS_EQBINARYTREE_H
