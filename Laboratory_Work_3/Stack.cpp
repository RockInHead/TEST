#include"Stack.h"
#include <iostream>

using namespace std;

////Размер текущего списка
//int _size;
//
////Указатель на последний элемент стэка.
//Node* _top;

//Конструктор по умолчанию для списка
Stack::Stack() :_size(0), _top(nullptr),_head(nullptr) {}

int Stack::GetTop() {
	if (_top != nullptr) {
		return _top->Data;
	}
	return 0;
}

int Stack::GetSize() const {
	return _size;
}

void Stack::InitRoot(int Data) {
	_head = new Node(Data);
	_top = _head;
	_size++;
}

//Возвращает текущий список
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
		} while (temp != nullptr); // условие окончания обхода
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
		return -1; // Стек пуст
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

		while (temp->Next->Next != nullptr) {
			temp = temp->Next; // Идём до предпоследнего узла
		}
		poppedElement = temp->Next->Data;
		delete temp->Next; // Удаляем последний узел
		temp->Next = nullptr; // Предпоследний элемент становится последним
		_top = temp; // Обновляем _top
	}

	_size--; // Уменьшаем размер
	return poppedElement;





	//if (_size != 0) {
	//	int poppedElement;
	//	if (_size == 1) {
	//		poppedElement = _head->Data;
	//		/*delete _head;*/
	//		_head = nullptr;
	//		_top = nullptr;
	//		_size=0;
	//		return poppedElement;
	//	}
	//	Node* temp = _head;
	//	/*if (_size > 2) {*/
	//		while (temp->Next->Next != nullptr) {
	//			temp = temp->Next;
	//		}
	//		poppedElement = temp->Next->Data;
	//		temp->Next = nullptr;
	//		_top = temp;
	//		_size--;
	//		return poppedElement;
	//	
	//	/*else if(_size==2){
	//		poppedElement = _head->Next->Data;
	//		_head->Next = nullptr;
	//		_top = _head;
	//		_size--;
	//		return poppedElement;
	//	}*/
	//	
	//}
	//return -1;
	
}

void Stack::ClearStack() {
	if (_size != 0) {
		while (_size != 0) {
			Pop();
		}
	}
}

//Stack Stack::CopyStack(Stack inputStack) {
//	Stack tempStack;
//	Stack copiedStack;
//
//	while (inputStack.GetSize() != 0) {
//		int value = inputStack.Pop();
//		tempStack.Push(value); // Копируем элементы во временный стек
//	}
//
//	while (tempStack.GetSize() != 0) {
//		int value = tempStack.Pop();
//		//inputStack.Push(value); // Восстанавливаем оригинал
//		copiedStack.Push(value); // Копируем в копию
//	}
//	return copiedStack;
//}
