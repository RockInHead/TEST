#ifndef CARTESIANNODE_H
#define CARTESIANNODE_H

#include <iostream>
struct CartesianNode
{
    int start = 0;
    int end = 20;
    int x = rand() % (end - start + 1) + start;

    //Ключ элемента.
    int Key;

    //Приоритет элемента.
    int Priority;

    //Указатель на левый элемент дерева.
    CartesianNode* Left;

    //Указатель на правый элемент дерева.
    CartesianNode* Right;

    //Конструкторы
    CartesianNode() : Key(-1),Priority(x), Left(nullptr), Right(nullptr) {}
    CartesianNode(int key) : Key(key), Priority(x), Left(nullptr), Right(nullptr) {}
};
#endif
