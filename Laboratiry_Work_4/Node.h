#ifndef NODE_H
#define NODE_H

#include <iostream>
struct Node
{
    // люч строка.
    std::string Key;

    //«начение элемента.
    int Value;

    //”казатель на следующий элемент, при возникновении коллизий.
    Node* Next;

    //”казатель на предыдущий элемент, при возникновении коллизий.
    Node* Prev;

    Node():Key(""), Value(0), Next(nullptr), Prev(nullptr){}
    Node(const std::string& k, int v) : Key(k), Value(v), Next(nullptr) {}
};
#endif