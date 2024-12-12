#ifndef HASHTABLE_H
#define HASHTABLE_H

#include"Node.h"
#include <iostream>

using namespace std;

class HashTable {
private:
	//Минимальная вместимость хеш-таблицы.
	const int MinCapacity = 5;

	//Фактор рсота для хеш-таблицы.
	double _growthFactor = 1.5;

	//Вместимость хеш-таблицы.
	int _capacity;

	//Размер текущей хеш-таблицы.
	int _size;

	//Указатель, на массив указатлей значений текущей хеш-таблицы.
	Node** _hashTable;

	//Проверяет, если у элементов одинаковые ключи, то приравнивает value перевого элемента value второго элемента.
	bool CompareKeys(Node* nodeFirst,Node* nodeSecond);

	//Создает новую хеш-таблицу с новой вместимостью. Переуказывает указатель на новую хеш-таблицу.
	void CreateNewHashTable(int capacity);

	//Изменяет вместимость хеш-таблицы, создавая новую хеш-таблицу.
	void ResizeHashTable();

public:

	//Конструктор по умолчанию.
	HashTable();

	//Получить текущую хеш-таблицу.
	Node** GetHashTable();

	//Получить текущий размер хеш-таблицы.
	int GetSize();

	//Получить вместимость текущий хеш-таблицы.
	int GetCapacity();

	//Добавить элемент в хэш-таблицу.
	void Put(string key, int data);

	//Простая хеш-функция.
	int Hash(string key);

	//Хеш-функция Пирсона. Возвращает хеш, учитывая вместимость хеш-таблицы.
	unsigned int PearsonHash(string key, int capacity);

	//Ищет значение по ключу. Возврщает значение элемента.
	int SearchingValue(string key);

	//Удаляем элемент по ключу.
	void DeleteElement(string key);

};
#endif