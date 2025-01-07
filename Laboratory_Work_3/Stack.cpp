#include"Stack.h"
#include <iostream>
using namespace std;

//Конструктор по умолчанию для списка
Stack::Stack() :_size(0), _top(nullptr),_head(nullptr) {}

//Получить значение верхнего элемента.
int Stack::GetTop() {
	if (_top != nullptr) {
		return _top->Data;
	}
	return 0;
}

//Получить размер текущего стэка.
int Stack::GetSize() const {
	return _size;
}

//Инициализация корневого узла.
void Stack::InitRoot(int Data) {
	_head = new Node(Data);
	_top = _head;
	_size++;
}

//Возвращает текущий список.
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

//Добавить элемент в конец стэка.
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

//Удалить последний элемент стэка.
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
		// Идём до предпоследнего узла
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

//Очистить весь стэк.
void Stack::ClearStack() {
	if (_size != 0) {
		while (_size != 0) {
			Pop();
		}
	}
}


