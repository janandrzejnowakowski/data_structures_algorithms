//
// Created by noj on 15.11.20.
//
// linked_list_algorithms.h

#include "data_structures/SinglyLinkedList.h"

#ifndef LINKED_LIST_ALGORITHMS_H
#define LINKED_LIST_ALGORITHMS_H

template <class T>
SLLNode<T>* swapEverySecondSLLNode(SLLNode<T>* head);
template <class T>
void swapEverySecondSLLNodeByValue(SLLNode<T>* head);
template <class T>
bool hasLoop(SLLNode<T>* head);

#include "algorithms/has_loop.tpp"
#include "algorithms/swap_every_second_node.tpp"

#endif