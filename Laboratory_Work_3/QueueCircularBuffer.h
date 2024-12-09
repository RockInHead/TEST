#ifndef QUEUECIRCULARBUFFER_H
#define QUEUECIRCULARBUFFER_H
#include <iostream>
#include"CircularBuffer.h"
using namespace std;

class QueueCircularBuffer {
private:

	//Цикличкский буфер.
	CircularBuffer _circularBuffer = CircularBuffer();

	//Текущая очередь.
	int* _queue = _circularBuffer.GetCircularBuffer();

	//Вместимость очереди.
	int _capacity= _circularBuffer.GetCapacity();

	//Размер очереди.
	int _size= _circularBuffer.GetSize();

	//Голова очереди.
	int _head= _circularBuffer.GetHead();

	//Хвост очереди.
	int _tail= _circularBuffer.GetTail();

public:
	//Констуктор по умолчанию.
	QueueCircularBuffer();

	//Получить текущуб очередь.
	int* GetQueue();

	//Получить хвост.
	int GetTail();

	//Получить голову.
	int GetHead();

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