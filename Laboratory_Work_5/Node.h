#ifndef NODE_H
#define NODE_H
#include <iostream>

//Узел бинарного дерева, хранящий значение
//и указатели на левый и правый элементы.
struct Node
{
    //Значение элемента.
    int Data;

    //Указатель на левый элемент дерева.
    Node* Left;

    //Указатель на правый элемент дерева.
    Node* Right;

    //Конструкторы
    Node() : Data(-1), Left(nullptr), Right(nullptr) {}
    Node(int data) : Data(data), Left(nullptr), Right(nullptr) {}
};
#endif