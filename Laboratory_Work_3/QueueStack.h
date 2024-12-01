#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include"Stack.h"
#include <iostream>
class QueueStack {
private:

	//Стэк номер 1.
	Stack _stack_1 = Stack();

	//Стэк номер 2.
	Stack _stack_2 = Stack();

	//Вместимость текущей очереди.
	int _capacity;

	//Размер текущей очереди.
	int _size;
public:
	//Констуктор по умолчанию.
	QueueStack();

	//Получить текущуб очередь.
	int* GetQueue();

	////Получить хвост.
	//int GetTail();

	////Получить голову.
	//int GetHead();

	//Вернет текую вместимосоть очереди.
	int GetCapacity();

	//Вернет текущий размер очереди.
	int GetSize();

	//Добавление элемента в конец очереди.
	void Enqueue(int data);

	//Удаление первого элемнета в очереди.
	int Dequeue();

	//Очищает всю очередь.
	void ClearQueue();
};
#endif