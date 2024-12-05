#include"Node.h"
Node::Node() {
    this->Data = -1;
    this->Next = nullptr;
    this->Prev = nullptr;
}
//Конструктор для инициализации узла с входящим значением.
Node::Node(int Data) 
{
    this->Data = Data;
    this->Next = nullptr;
    this->Prev = nullptr;
}