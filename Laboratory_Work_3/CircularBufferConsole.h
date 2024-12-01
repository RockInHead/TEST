#ifndef CIRCULATBUFFERCONSOLE_H
#define CIRCULATBUFFERCONSOLE_H

#include <iostream>
#include"CircularBuffer.h"
#include"Colors.h"
using namespace std;

//Показать текущий стэк в строку.
void ShowBuffer(CircularBuffer buffer);

//Показать меню для стэка.
void MenuBuffer(CircularBuffer buffer);

//Вызвать консольное меню для стэка.
void CircularBufferConsole(CircularBuffer& buffer);


#endif // STACKCONSOLE_H