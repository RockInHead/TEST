#ifndef QUEUECIRCULARBUFFERCONSOLE_H
#define QUEUECIRCULARBUFFERCONSOLE_H
#include <iostream>
#include"Colors.h"
#include"QueueCircularBuffer.h"

//�������� ������� ������� � ������.
void ShowQueue(QueueCircularBuffer queue);

//�������� ���� ��� �������.
void MenuQueue(QueueCircularBuffer queue);

//������� ���������� ���� ��� �������.
void QueueConsole(QueueCircularBuffer& queue);

#endif