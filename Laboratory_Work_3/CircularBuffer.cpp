#include"CircularBuffer.h"
//Голова буфера.
int _head;

//Хвост буфера.
int _tail;

//Голова буфера.
int  CircularBuffer::GetHead() {
    return _head;
}
//Хвост буфера.
int  CircularBuffer::GetTail() {
    return _tail;
}
//Получить текущую длину массива
int CircularBuffer::GetSize()  {
    return _size;
}

//Получить текущую вместитеьность массива
int CircularBuffer::GetCapacity() {
    return _capacity;
}

//Получить массив
int* CircularBuffer::GetCircularBuffer() {
    return _buffer;
}

//Констуктор по умолчанию.
CircularBuffer::CircularBuffer() : _capacity(10), _head(0), _tail(0), _size(0) {
    _buffer = new int[_capacity](); // Инициализация массива нулями
}
//Свободные элементы буфера.
int CircularBuffer::GetFreeElements() {
    return _capacity - _size;
}
//Занятые элементы буфера.
int CircularBuffer::GetOccupiedElements() {
    return _size;
}

// Добавляет элемент в буфер
void CircularBuffer::Push(int data) {  
    
    if (_head == _tail && _size!=0) {
        _tail = (_tail + 1) % _capacity;
    }

    _buffer[_head] = data;          // Записываем элемент в буфер
    _head = (_head + 1) % _capacity;

    if (_size < _capacity) {
        _size++;
    }

}
//Удаляет самый старый элемент массива и возвращает его значение.
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
//Очищает весь буфер.
void CircularBuffer::ClearBuffer() {
    if (_size != 0) {
        while (_size != 0) {
            Pop();
        }
    }
}