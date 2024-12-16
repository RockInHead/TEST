#ifndef CARTESIANNODE_H
#define CARTESIANNODE_H

#include <iostream>
struct CartesianNode
{
    //Ключ элемента.
    int Key;

    //Приоритет элемента.
    int Priority;

    //Указатель на левый элемент дерева.
    CartesianNode* Left;

    //Указатель на правый элемент дерева.
    CartesianNode* Right;

    //Конструкторы
    CartesianNode() : Key(-1),Priority(-1), Left(nullptr), Right(nullptr) {}
    CartesianNode(int key,int priority) : Key(key), Priority(priority), Left(nullptr), Right(nullptr) {}
};
#endif
