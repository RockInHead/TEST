#ifndef QUEUESTACKCONSOLE_H
#define QUEUESTACKCONSOLE_H
#include <iostream>
#include"Colors.h"
#include"QueueStack.h"

//Показать текущую очередь в строку.
void ShowQueue(QueueStack& queue);

//Показать меню для очереди.
void MenuQueue(QueueStack& queue);

//Вызвать консольное меню для очереди.
void QueueStackConsole(QueueStack& queue);



#endif