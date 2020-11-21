//
// Created by noj on 15.11.20.
//
// swap_every_second_node.h

#include "data_structures/LinkedList.h"

#ifndef LINKED_LIST_ALGORITHMS_H
#define LINKED_LIST_ALGORITHMS_H

template <class T>
Node<T>* swapEverySecondNode(Node<T>* head);
template <class T>
void swapEverySecondNodeByValue(Node<T>* head);
template <class T>
bool hasLoop(Node<T>* head);

#include "algorithms/has_loop.tpp"
#include "algorithms/swap_every_second_node.tpp"

#endif