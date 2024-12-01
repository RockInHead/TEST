#ifndef QUEUECIRCULARBUFFER_H
#define QUEUECIRCULARBUFFER_H
#include <iostream>
#include"CircularBuffer.h"
using namespace std;

class QueueCircularBuffer {
private:
	CircularBuffer _circularBuffer = CircularBuffer();
	int* _queue = _circularBuffer.GetCircularBuffer();
	int _capacity= _circularBuffer.GetCapacity();
	int _size= _circularBuffer.GetSize();
	int _head= _circularBuffer.GetHead();
	int _tail= _circularBuffer.GetTail();

public:
	QueueCircularBuffer();

	int* GetQueue();

	int GetTail();

	int GetHead();

	int GetCapacity();

	int GetSize();

	//Добавление элемента в конец очереди.
	void Enqueue(int data);

	//Удаление первого элемнета в очереди.
	int Dequeue();

};

#endif