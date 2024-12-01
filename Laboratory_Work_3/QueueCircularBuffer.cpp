#include"QueueCircularBuffer.h"

//Констуктор по умолчанию.
QueueCircularBuffer::QueueCircularBuffer() {
	_circularBuffer= CircularBuffer(); 
}

int QueueCircularBuffer::GetCapacity() {
	return _circularBuffer.GetCapacity();
}
int  QueueCircularBuffer::GetSize() {
	return _circularBuffer.GetSize();
}

int  QueueCircularBuffer::GetHead() {
	return _circularBuffer.GetHead();
}

int  QueueCircularBuffer::GetTail() {
	return _circularBuffer.GetTail();
}

int* QueueCircularBuffer::GetQueue() {
	int* resArray = new int[_size];
	int* array = _circularBuffer.GetCircularBuffer();
	for (int i = 0; i < _size; i++) {

		int index = (_circularBuffer.GetTail() + i);
		resArray[i] = array[index];
	}
	return resArray;
}
void QueueCircularBuffer::Enqueue(int data) {
	if (_size < _capacity) {
		_circularBuffer.Push(data);
		_size++;
	}
}

int QueueCircularBuffer::Dequeue() {
	if (_size != 0) {
		int value =_circularBuffer.Pop();
		_size--;
		return value;
	}
	return -1;
}