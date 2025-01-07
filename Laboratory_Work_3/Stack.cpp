#include"Stack.h"
#include <iostream>
using namespace std;

//����������� �� ��������� ��� ������
Stack::Stack() :_size(0), _top(nullptr),_head(nullptr) {}

//�������� �������� �������� ��������.
int Stack::GetTop() {
	if (_top != nullptr) {
		return _top->Data;
	}
	return 0;
}

//�������� ������ �������� �����.
int Stack::GetSize() const {
	return _size;
}

//������������� ��������� ����.
void Stack::InitRoot(int Data) {
	_head = new Node(Data);
	_top = _head;
	_size++;
}

//���������� ������� ������.
int* Stack::GetStack() {
	int sizeOfStack = _size;
	int* stack = new int[sizeOfStack];
	int index = 0;
	if (_head != nullptr) {
		Node* temp = _head;
		do{
			stack[index] = temp->Data;
			temp = temp->Next;
			index++;
		} while (temp != nullptr);
	}
	return stack;

}

//�������� ������� � ����� �����.
void Stack::Push(int Data) {
	if (_size == 0) {
		InitRoot(Data);
		return;
	}
	Node* newNode = new Node(Data);

	Node* temp = _head;
	while (temp->Next) {
		temp = temp->Next;
	}
	temp->Next = newNode;
	_top = newNode;
	_size++;
}

//������� ��������� ������� �����.
int Stack::Pop() 
{
	if (_size == 0) {
		return -1; 
	}

	Node* temp = _head;
	int poppedElement;

	if (_size == 1) {
		poppedElement = _head->Data;
		delete _head;
		_head = nullptr;
		_top = nullptr;
	}
	else {
		// ��� �� �������������� ����
		while (temp->Next->Next != nullptr) {
			temp = temp->Next; 
		}
		poppedElement = temp->Next->Data;
		delete temp->Next; 
		temp->Next = nullptr; 
		_top = temp; 
	}

	_size--; 
	return poppedElement;	
}

//�������� ���� ����.
void Stack::ClearStack() {
	if (_size != 0) {
		while (_size != 0) {
			Pop();
		}
	}
}


