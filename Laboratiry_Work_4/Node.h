#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
struct Node
{
    //Ключ строка.
    string Key;

    //Значение элемента.
    int Value;

    //Указатель на следующий элемент, при возникновении коллизий.
    Node* Next;

    //Указатель на предыдущий элемент, при возникновении коллизий.
    Node* Prev;

    //Констукторы
    Node():Key(""), Value(0), Next(nullptr), Prev(nullptr){}
    Node(const string& k, int v) : Key(k), Value(v), Next(nullptr), Prev(nullptr) {}
};
#endif