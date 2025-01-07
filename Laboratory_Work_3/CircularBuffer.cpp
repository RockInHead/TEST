#include"CircularBuffer.h"

//�������� ������ ������.
int  CircularBuffer::GetHead() {
    return _head;
}

//�������� ����� ������.
int  CircularBuffer::GetTail() {
    return _tail;
}

//�������� ������� ����� �������
int CircularBuffer::GetSize()  {
    return _size;
}

//�������� ������� �������������� �������
int CircularBuffer::GetCapacity() {
    return _capacity;
}

//�������� ������.
int* CircularBuffer::GetCircularBuffer() {
    return _buffer;
}

//���������� �� ���������.
CircularBuffer::CircularBuffer() : _capacity(10), _head(0), _tail(0), _size(0) {
    _buffer = new int[_capacity](); // ������������� ������� ������
}

//��������� �������� ������.
int CircularBuffer::GetFreeElements() {
    return _capacity - _size;
}

//������� �������� ������.
int CircularBuffer::GetOccupiedElements() {
    return _size;
}

//��������� ������� � �����
void CircularBuffer::Push(int Data) {  
    
    if (_head == _tail && _size!=0) {
        _tail = (_tail + 1) % _capacity;
    }

    // ���������� ������� � �����
    _buffer[_head] = Data;         
    _head = (_head + 1) % _capacity;

    if (_size < _capacity) {
        _size++;
    }
}

//������� ����� ������ ������� ������� � ���������� ��� ��������.
int CircularBuffer::Pop() {
    if (_size != 0) {
       
        int value =_buffer[_tail];
        
        _tail = (_tail + 1) % _capacity;
        _size--;
        return value;
    }
    else {
        return -1;
    }
 }

//������� ���� �����.
void CircularBuffer::ClearBuffer() {
    if (_size != 0) {
        while (_size != 0) {
            Pop();
        }
    }
}