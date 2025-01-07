#include"List.h"
#include <iostream>
using namespace std;

//�������������� ������ ������.
void List::InitRoot(int Data) {
	Node* root = new Node();
	_head = root;
	
	_head->Data = Data;
	_head->Next = nullptr; 
	_head->Prev = nullptr; 
	_size++;
}

//����������� �� ��������� ��� ������
List::List():_size(0),_head(nullptr),_tail(nullptr) {}

//������� ������������, ������� ������.
int List::GetHead() {
	if (_head != nullptr) {
		return _head->Data;
	}
	if (_head == nullptr && _size == 0) {
		return 0;
	}
}

//������� ������������, ������� �����.
int List::GetTail() {
	if (_tail != nullptr){
		return _tail->Data;
     }
	if (_tail == nullptr && _size < 2) {
		return 0;
	}
	
}

//���������� ������ �������� ������.
int List::GetSize() {

	return _size;
}

//���������� ������� ������
int* List::GetList() {
	int sizeOfArray = GetSize();
	int* array= new int[sizeOfArray];
	int index = 0;
	if (_head != nullptr) {
		Node* temp = _head;
		do {
			array[index] = temp->Data;
			temp = temp->Next;
			index++;
		} while (temp != nullptr); 
	}
	return array;
}

//������� ���������� �������� � ����� �������.
void List::AddNodeAtEnd(int Data)
{
	//������� ����� �������, � ��������� data
	Node* newNode = new Node(Data);

	//���������, ������� �� "������" �������, ���� ���, �������.
	if (_head == nullptr) 
	{
		InitRoot(Data);
		return;
	}
	
	Node* temp = _head;
	while (temp->Next != nullptr) {
		temp = temp->Next;
	}

	temp->Next = newNode;
	newNode->Prev = temp;
	_size++;

	if ( _size > 1)
	{
		_tail = newNode;
	}
}

//������� ���������� �������� � ������ �������.
void List::AddNodeAtStart(int Data) {
	Node* newNode = new Node(Data);
	//���������, ������� �� "������" �������, ���� ���, �������
	if (_head == nullptr)
	{
		InitRoot(Data);
		return;
	}

	newNode->Next = _head;
	_head->Prev = newNode;
	_head = newNode;
	_size++;
	if (_size == 2) {
		_tail = _head->Next;
	}
}

//��������� ������� � ������ ����� ������������ ���������
void List::InsertBefore(int Data, int indexOfElement) {
	Node* newNode = new Node(Data);
	Node* temp;

	if (indexOfElement <= _size && indexOfElement >= 0) {
		if (_head == nullptr)
		{
			InitRoot(Data);
			return;
		}
		if (indexOfElement == 0) {
			AddNodeAtStart(Data);
			return;
		}
		if (indexOfElement == _size) {
			AddNodeAtEnd(Data);
			return;
		}

		//����������� � ������ ��� � ������ ����� �������.
		if (indexOfElement < _size / 2) {
			temp = _head;
			for (int i = 0; temp != nullptr && i < indexOfElement-1; i++) {
				temp = temp->Next;
			}
		}
		else {
			temp = _tail;
			for (int i = _size; temp != nullptr && i > indexOfElement; i--) {
				temp = temp->Prev;
			}
		}
		newNode->Next = temp->Next;
		newNode->Prev = temp;
		if (temp->Next != nullptr) {
			temp->Next->Prev = newNode;
		}
		temp->Next = newNode;
		_size++;
	}
}

//�������� ����� �������� ������.
int List::LinearSearch(int seacrhingElement) {
	Node* temp = _head;
	for (int i = 0; i < _size; i++) {
		if (temp->Data == seacrhingElement) {
			return i;
		}
		temp = temp->Next;
	}
	return -1;
}

//��������� ������� � ������ ����� ������������� ��������
void List::InsertAfter(int Data, int indexOfElement)
{
	if (indexOfElement >= 0) {
		InsertBefore(Data, indexOfElement + 1);
	}
}

//������������� ������ �� ��������� ������� ������. ������� ������ �������.
void List::DeleteHead() {
	_head = _head->Next;
	if (_head != nullptr) {
		_head->Prev = nullptr;
	}
	
}

//������������� ����� �� ���������� ������� ������. ������� ����� �������.
void List::DeleteTail() {
	_tail = _tail->Prev;
	if (_tail != nullptr) {
		_tail->Next = nullptr;
	}
	
}

//������� �������� �������� �� �������.
void List::DeleteNodeIndex(int deletedIndex) 
{
	//���� "������" ����������.
	if (_head != nullptr && deletedIndex < _size && deletedIndex >= 0) 
	{
		//���� ���� ������� � ������, ������� �������� � ������� � �������.
		if (_size == 1 && _tail!=nullptr) {
			DeleteHead();
			DeleteTail();
			_size--;
			return;
		}
		//���� ������� ������.
		if (deletedIndex == 0 ) {
			DeleteHead();
			_size--;
			return;
		}
		//������� �����.
		if (deletedIndex == _size - 1 ) {
			DeleteTail();
			_size--;
			return;
		}
		Node* temp;
		//����������� � ������ ��� � ������ ����� �������.
		if (deletedIndex < _size / 2) {
			temp = _head;
			for (int i = 0; temp != nullptr && i < deletedIndex; i++) {
				temp = temp->Next;
			}
		}
		else  {
			temp = _tail;
			for (int i = _size-1; temp != nullptr && i > deletedIndex; i--) {
				temp = temp->Prev;
			}
		}
		//������� �������.
		if (temp != nullptr) {
			if (temp->Next != nullptr) {
				temp->Next->Prev = temp->Prev;
			}
			else if (temp->Next == nullptr) {
				_tail = temp->Prev;
			}
			if (temp->Prev != nullptr) {
				temp->Prev->Next = temp->Next;
			}
			delete temp;
			_size--;
		}
	}
}

//������ ������� ��� �������� �������� ������.
void List::SwapNodes(Node* firstNode,Node* secondNode) 
{
	Node* prev1;
	Node* prev2;
	Node* next1;
    Node* next2;

	prev1 = firstNode->Prev;  
	prev2 = secondNode->Prev;  
	next1 = firstNode->Next; 
	next2 = secondNode->Next; 
	secondNode->Next = firstNode;
	secondNode->Prev = prev1;
	firstNode->Next = next2;
	firstNode->Prev = secondNode;

	if (next2 != nullptr) {
		next2->Prev = firstNode;
	}
	if (firstNode != _head) {
		prev1->Next = secondNode;
	}
	if (prev1 == nullptr) {
		_head= secondNode;
	}
	if (next2 == nullptr) {
		_tail = firstNode;
	}
	
}

//��������� ������ �� �����������.
void List::SortList()
{
	Node* temp = _head;
	for (int i = 0; i < _size; i++) {
		temp = _head;
		for (int j = 0; j < _size; j++) {
			if (temp != nullptr && temp->Next!=nullptr) {
				if (temp->Data > temp->Next->Data) {
					SwapNodes(temp, temp->Next);
				}
				temp = temp->Next;
			}
		}
	}
}


