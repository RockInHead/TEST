#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H
#include <iostream>
using namespace std;

class CircularBuffer {
private:
	int _capacity;
	int _size;
	int _head;
	int _tail;
	int* _buffer;
public:
	
	//Возвращает голову буфера.
	int GetHead();

	//Возвращает хвост буфера.
	int GetTail();

	//Констуктор по умолчанию для кольцеового буффера.
	CircularBuffer();

	//Возвращает вместимость массива.
	int GetCapacity();

	//Возвращает размер массива.
	int GetSize();

	//Возвращает текущий кольцевой буффер.
	int* GetCircularBuffer();

	//Возвращает количество свободных мест в текущем буффере.
	int GetFreeElements();

	//Возвращает количество занятых мест в текущем буффере.
	int GetOccupiedElements();

	//Добавляет элемент в буфер.
	void Push(int data);

	//Удаляет самый старый элемент из буфера.
	int Pop();

	//Очищает весь буфер.
	void ClearBuffer();
};




#endif
