#include"Node.h"

//����������� �� ���������
Node::Node() {
    this->Data = -1;
    this->Next = nullptr;
  
}
//����������� ��� ������������� ���� � �������� ���������.
Node::Node(int Data)
{
    this->Data = Data;
    this->Next = nullptr;
}