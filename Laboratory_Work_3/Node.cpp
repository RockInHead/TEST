#include"Node.h"

//Конструктор по умолчанию
Node::Node() {
    this->Data = -1;
    this->Next = nullptr;
  
}
//Конструктор для инициализации узла с входящим значением.
Node::Node(int Data)
{
    this->Data = Data;
    this->Next = nullptr;
}