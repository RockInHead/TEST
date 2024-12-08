#ifndef HASHTABLE_H
#define HASHTABLE_H

//#include"Node.h"
#include <iostream>
using namespace std;

class HashTable {
private:
	//Размер текущего стэка.
	int _size;

	//Указатель на голову стэка.
	/*Node* _head;*/

	//Указатель на последний элемент стэка.
	/*Node* _top;*/

public:

	//Конструктор по умолчанию.
	HashTable();

	//Добавить элемент в хэш-таблицу.
	void Put(string key, int data);

	//Удалить последний элемент стэка.
	int Pop();

	//Очистить весь стэк.
	void ClearStack();

};
#endif