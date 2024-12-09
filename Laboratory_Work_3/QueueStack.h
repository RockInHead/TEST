#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include"Stack.h"
#include <iostream>
class QueueStack {
private:

	//Стэк номер 1.
	Stack _stack1;

	//Стэк номер 2.
	Stack _stack2;

	//Вместимость текущей очереди.
	int _capacity;

	//Размер текущей очереди.
	int _size;

	//Делает копию текущего стэка и возвращает в качестве значения.
	Stack CopyStack(Stack& inputStack);

public:

	//Констуктор по умолчанию.
	QueueStack();

	//Получить текущую очередь.
	int* GetQueueStack();

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