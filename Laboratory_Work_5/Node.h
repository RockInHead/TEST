#ifndef NODE_H
#define NODE_H

#include <iostream>
struct Node
{
    //«начение элемента.
    int Data;

    //”казатель на левый элемент дерева.
    Node* Left;

    //”казатель на правый элемент дерева.
    Node* Right;

    Node() : Data(-1), Left(nullptr), Right(nullptr) {}
    Node(int data) : Data(data), Left(nullptr), Right(nullptr) {}
};
#endif