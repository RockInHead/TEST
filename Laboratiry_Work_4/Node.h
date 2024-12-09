#ifndef NODE_H
#define NODE_H

#include <iostream>
struct Node
{
    //Ключ строка.
    std::string Key;

    //Значение элемента.
    int Value;

    //Указатель на следующйи элемент, при возникновении коллизий.
    Node* Next;

    Node() :Key(""), Value(0), Next(nullptr) {}
    Node(const std::string& k, int v) : Key(k), Value(v), Next(nullptr) {}
};
#endif