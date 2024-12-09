#ifndef HASHTABLE_H
#define HASHTABLE_H

#include"Node.h"
#include <iostream>

using namespace std;

class HashTable {
private:
	int _capacity;

	//Размер текущего стэка.
	int _size;

	//Указатель на голову стэка.
	/*Node* _head;*/

	//Указатель на последний элемент стэка.
	/*Node* _top;*/
	Node* _table;

public:

	//Конструктор по умолчанию.
	HashTable();
	

	//Добавить элемент в хэш-таблицу.
	void Put(string key, int data);

	int Hash(string key);

	int GetNode(string key);

	unsigned int PearsonHash(string key);
};
#endif