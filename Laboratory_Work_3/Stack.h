#ifndef STACK_H
#define STACK_H
#include"Node.h"
#include <iostream>

//����� �� ����, ������������� �� ������������� ������.
class Stack {
private:
	//������ �������� �����.
	int _size;

	//��������� �� ������ �����.
	Node* _head;

	//��������� �� ��������� ������� �����.
	Node* _top;

	//������� �������� ������� �����.
	void InitRoot(int data);
public:

	// ���������� ��������� ������� �����.
	int GetTop();

	// ���������� ������� ������ �����.
	int GetSize() const;

	//���������� ������� ����.
	int* GetStack();

	//����������� �� ���������.
	Stack();

	//�������� ������� � ����� �����.
	void Push(int data);

	//������� ��������� ������� �����.
	int Pop();

	//�������� ���� ����.
	void ClearStack();

};
#endif
