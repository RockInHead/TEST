#ifndef QUEUECIRCULARBUFFERCONSOLE_H
#define QUEUECIRCULARBUFFERCONSOLE_H
#include <iostream>
#include"Colors.h"
#include"QueueCircularBuffer.h"

//Показать текущую очередь в строку.
void ShowQueue(QueueCircularBuffer queue);

//Показать меню для очереди.
void MenuQueue(QueueCircularBuffer queue);

//Вызвать консольное меню для очереди.
void QueueConsole(QueueCircularBuffer& queue);



#endif