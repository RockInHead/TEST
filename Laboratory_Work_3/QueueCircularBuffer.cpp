#include"QueueCircularBuffer.h"

//Конструктор по умолчанию.
QueueCircularBuffer::QueueCircularBuffer() {
	_circularBuffer= CircularBuffer(); 
}

//Вернет текую вместимосоть очереди.
int QueueCircularBuffer::GetCapacity() {
	return _circularBuffer.GetCapacity();
}

//Вернет текущий размер очереди.
int  QueueCircularBuffer::GetSize() {
	return _circularBuffer.GetSize();
}
//Получить голову.
int  QueueCircularBuffer::GetHead() {
	return _circularBuffer.GetHead();
}

//Получить хвост.
int  QueueCircularBuffer::GetTail() {
	return _circularBuffer.GetTail();
}

//Получить текущую очередь.
int* QueueCircularBuffer::GetQueue() {
	int* resArray = new int[_size];
	int* array = _circularBuffer.GetCircularBuffer();
	for (int i = 0; i < _size; i++) {

		int index = (_circularBuffer.GetTail() + i)%_capacity;
		resArray[i] = array[index];
	}
	return resArray;
}

//Добавление элемента в конец очереди.
void QueueCircularBuffer::Enqueue(int Data) {
	if (_size < _capacity) {
		_circularBuffer.Push(Data);
		_size++;
	}
}

//Удаление первого элемнета в очереди.
int QueueCircularBuffer::Dequeue() {
	if (_size != 0) {
		int value =_circularBuffer.Pop();
		_size--;
		return value;
	}
	return -1;
}

//Очищает всю очередь.
void QueueCircularBuffer::ClearQueue() {
	if (_size != 0) {
		while (_size != 0) {
			Dequeue();
		}
	}
}