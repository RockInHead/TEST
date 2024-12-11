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
	Node** _table;
	/*Node* _table = new Node[5];*/

	bool CompareKeys(Node* nodeFirst,Node* nodeSecond);

public:

	//Конструктор по умолчанию.
	HashTable();

	Node** GetHashTable();

	int GetSize();

	int GetCapacity();


	//Добавить элемент в хэш-таблицу.
	void Put(string key, int data);

	int Hash(string key);

	//Ищет значение по ключу. Возврщает значение элемента.
	int SearchingValue(string key);

	//Удаляем элемент по ключу.
	void DeleteElement(string key);

	unsigned int PearsonHash(string key);
};
#endif