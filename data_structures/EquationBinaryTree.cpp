//
// Created by noj on 28.11.20.
//

#include "BinaryTree.h"

EBT::EBT(const std::vector<std::string> &operations, const std::vector<double> &numbers)
{

    if (operations.empty() && numbers.size() == 1)
    {
        left = nullptr;
        right = nullptr;
        value = std::to_string(numbers[0]);
        return;
    }
    unsigned op_size = operations.size();
    unsigned num_size = numbers.size();
    unsigned test_value = 2;
    while (op_size > test_value)
    {
        test_value *= 2;
    }
    if (test_value != num_size || num_size != op_size + 1)
    {
        std::cout << "Invalid relation between the number of numbers and operations. Size of numbers needs to be equal to the size of operations + 1" << std::endl;
        return;
    }
    if (!(operations[0] == "+" || operations[0] == "-" || operations[0] == "*" || operations[0] == "/"))
    {
        std::cout << "Invalid operation string: " << operations[0] << std::endl;
        return;
    }
    value = operations[0];
    std::vector<std::string> right_operations;
    std::vector<std::string> left_operations;
    std::vector<double> right_numbers;
    std::vector<double> left_numbers;

// tester value                  //    0 2 2 4 4 4 4 8 8 8  8  8  8  8  8  16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16
// i (vector index + 1)          //    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
// where should the operation go //    - l r l l r r l l l  l  r  r  r  r  l  l  l  l  l  l  l  l  r  r  r  r  r  r  r  r

    double tester = 2;
    for (unsigned i = 2; i <= op_size; ++i)
    {
        if (i >= 2 * tester)
            tester *= 2;
        if (i  < 1.5 * tester)
            left_operations.push_back(operations[i - 1]);
        else
            right_operations.push_back(operations[i - 1]);
    }

    for (unsigned i = 0; i < num_size; ++i)
    {
        if (i < num_size/2)
            left_numbers.push_back(numbers[i]);
        else
            right_numbers.push_back(numbers[i]);
    }
    left = new EBT(left_operations, left_numbers);
    right = new EBT(right_operations, right_numbers);
}

EBT::~EBT()
{
    delete left;
    delete right;
}

double EBT::calculateValue()
{
    if (!left || !right)
        return std::stod(value);
    if (value == "+")
        return left->calculateValue() + right->calculateValue();
    if (value == "-")
        return left->calculateValue() - right->calculateValue();
    if (value == "*")
        return left->calculateValue() * right->calculateValue();
    if (value == "/")
        return left->calculateValue() / right->calculateValue();
    std::cout << "ERROR: unrecognized operation " << value << std::endl;
    return 0;
}

std::string EBT::getString(bool show_result)
{
    std::string l = left ? left->getString(false) : "";
    std::string r = right ? right->getString(false) : "";
    std::string val = value;
    std::string ret;
    if (!l.empty() && !r.empty())
        ret = "(" + l + " " + val + " " + r + ")";
    else
        ret = val;
    if (show_result)
        ret += " = " + std::to_string(calculateValue());
    return ret;
}
