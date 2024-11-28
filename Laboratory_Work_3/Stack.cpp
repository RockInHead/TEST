#include"Stack.h"
#include <iostream>

using namespace std;

//Размер текущего списка
int _size;

//Указатель на последний элемент стэка.
Node* _top;
//Конструктор по умолчанию для списка
Stack::Stack() :_size(0), _top(nullptr) {}

int Stack::GetSize() {
	return _size;
}

void Stack::InitRoot(int data) {
	_top = new Node(data);
	_size++;
}

//Возвращает текущий список
int* Stack::GetStack() {
	int sizeOfStack = _size;
	int* stack = new int[sizeOfStack];
	int index = 0;
	if (_top != nullptr) {
		Node* temp = _top;
		do {
			stack[index] = temp->data;
			temp = temp->next;
			index++;
		} while (temp != nullptr); // условие окончания обхода
	}
	return stack;
	delete[] stack;

}



//Добавить элемент в конец стэка.
void Stack::Push(int data) {
	if (_size == 0) {
		InitRoot(data);
		return;
	}
	Node* newNode = new Node(data);
	Node* temp = _top;

	temp->next = newNode;
	_top = newNode;
	/*newNode = _top;*/
	/*newNode->next = newNode;
	_top = newNode;*/
	/*_top->next = newNode;
	_top = newNode;*/
	_size++;
}

//Удалить последний элемент стэка.
void Stack::Pop() {

}