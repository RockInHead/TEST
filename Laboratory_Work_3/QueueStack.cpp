#include"QueueStack.h"
#include <iostream>

using namespace std;

//Конструктор по умолчанию.
QueueStack::QueueStack():_stack1(), _stack2(), _size(0),_capacity(10) {}

//Вернет текую вместимосоть очереди.
int QueueStack::GetCapacity() {
	return _capacity;
}

//Вернет текущий размер очереди.
int QueueStack::GetSize() {
	return _size;
}

//Добавление элемента в конец очереди.
void QueueStack::Enqueue(int Data) {
	_stack1.Push(Data);
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
	while (_size != 0) {
		Dequeue();
	}
}

//Получить текущую очередь.
int* QueueStack::GetQueueStack() {
	Stack resStack;
	Stack copiedStack1;
	Stack copiedStack2;
	Stack reverseStack1;

	copiedStack1 = CopyStack(_stack1);
	while (copiedStack1.GetSize() != 0) {
		reverseStack1.Push(copiedStack1.Pop());
	}

	copiedStack2 = CopyStack(_stack2);
	while (copiedStack2.GetSize() != 0) {
		resStack.Push(copiedStack2.Pop());
	}

	while (reverseStack1.GetSize() != 0) {
		resStack.Push(reverseStack1.Pop());
	}

	return resStack.GetStack();

}

//Делает копию текущего стэка и возвращает в качестве значения.
Stack QueueStack::CopyStack(Stack& inputStack) {
	Stack tempStack;
	Stack copiedStack;

	while (inputStack.GetSize() != 0) {
		int value = inputStack.Pop();
		tempStack.Push(value); // Копируем элементы во временный стек
	}

	while (tempStack.GetSize() != 0) {
		int value = tempStack.Pop();
		inputStack.Push(value); // Восстанавливаем оригинал
		copiedStack.Push(value); // Копируем в копию
	}
	return copiedStack;
}

