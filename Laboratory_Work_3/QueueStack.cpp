#include"QueueStack.h"
#include <iostream>

using namespace std;
QueueStack::QueueStack():_stack1(), _stack2(), _size(0),_capacity(10) {

	//_stack2= Stack();
 //   _stack1 = Stack();
}


int QueueStack::GetCapacity() {
	return _capacity;
}
int QueueStack::GetSize() {
	return _size;
}

//Добавление элемента в конец очереди.
void QueueStack::Enqueue(int Data) {

	_stack1.Push(Data);
	/*int value = _stack1.Pop();*/
	_size++;
}

//Удаление первого элемнета в очереди.
int QueueStack::Dequeue() {
	if (_size != 0) {
		if (_stack2.GetSize() == 0) {
			while (_stack1.GetSize() != 0) {
				_stack2.Push(_stack1.Pop());
			}
		}
		_size--;
	}
	return _stack2.Pop();

}

//Очищает всю очередь.
void QueueStack::ClearQueue() {

}

int* QueueStack::GetQueueStack() {
	Stack resStack = Stack();
	/*static Stack reversStack1;
	Stack tempStack1 = _stack1;
	Stack tempStack2 = _stack2;

	
	while (tempStack2.GetSize() != 0) {
		resStack.Push(tempStack2.Pop());
	}*/

	
	
	Stack copiedStack1;
	Stack copiedStack2;
	Stack tempStack1; // Временный стек для копирования элементов
	Stack tempStack2; // Временный стек для копирования элементов


	while (_stack1.GetSize()!=0) {
		int value = _stack1.Pop();
		tempStack1.Push(value); // Копируем элементы во временный стек
		copiedStack1.Push(value);
	}

	while (_stack2.GetSize() != 0) {
		int value = _stack2.Pop();
		tempStack2.Push(value); // Копируем элементы во временный стек
	}

	// Восстанавливаем элементы в _stack1 и copiedStack
	while (tempStack1.GetSize()!= 0) {
		int value = tempStack1.Pop();
		_stack1.Push(value); // Восстанавливаем оригинал
		//copiedStack1.Push(value); // Копируем в копию
	}

	// Восстанавливаем элементы в _stack1 и copiedStack
	while (tempStack2.GetSize() != 0) {
		int value = tempStack2.Pop();
		_stack2.Push(value); // Восстанавливаем оригинал
		copiedStack2.Push(value); // Копируем в копию
	}

	while (copiedStack2.GetSize() != 0) {
		resStack.Push(copiedStack2.Pop());
	}

	int size = copiedStack1.GetSize();

	for (int i = 0; i < size; i++) {
		resStack.Push(copiedStack1.Pop());
	}

	return resStack.GetStack();

}
