#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H
#include <iostream>
using namespace std;

//����� ���������� �������, �������� �����������, ������ � ������� �� ������ � �����.
class CircularBuffer {
private:

	//����������� ������.
	int _capacity;

	//������� ������ ������.
	int _size;

	//������ ������.
	int _head;

	//����� ������.
	int _tail;

	//������� �����.
	int* _buffer;

public:
	
	//���������� ������ ������.
	int GetHead();

	//���������� ����� ������.
	int GetTail();

	//���������� �� ��������� ��� ����������� �������.
	CircularBuffer();

	//���������� ����������� �������.
	int GetCapacity();

	//���������� ������ �������.
	int GetSize();

	//���������� ������� ��������� ������.
	int* GetCircularBuffer();

	//���������� ���������� ��������� ���� � ������� �������.
	int GetFreeElements();

	//���������� ���������� ������� ���� � ������� �������.
	int GetOccupiedElements();

	//��������� ������� � �����.
	void Push(int Data);

	//������� ����� ������ ������� �� ������.
	int Pop();

	//������� ���� �����.
	void ClearBuffer();
};

#endif
