#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H
#include <iostream>
using namespace std;

//Класс кольцевого буффера, хранящий вместимость, размер и индексы на голову и хвост.
class CircularBuffer {
private:

	//Вместимость буфера.
	int _capacity;

	//Текущий размер буфера.
	int _size;

	//Голова буфера.
	int _head;

	//Хвост буфера.
	int _tail;

	//Текущйи буфер.
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
	void Push(int Data);

	//Удаляет самый старый элемент из буфера.
	int Pop();

	//Очищает весь буфер.
	void ClearBuffer();
};

#endif
