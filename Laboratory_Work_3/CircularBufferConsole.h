#ifndef CIRCULATBUFFERCONSOLE_H
#define CIRCULATBUFFERCONSOLE_H
#include <iostream>
#include"CircularBuffer.h"
#include"Colors.h"
using namespace std;

//�������� ������� ���� � ������.
void ShowBuffer(CircularBuffer buffer);

//�������� ���� ��� �����.
void MenuBuffer(CircularBuffer buffer);

//������� ���������� ���� ��� �����.
void CircularBufferConsole(CircularBuffer& buffer);


#endif