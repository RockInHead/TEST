#ifndef HASHTABLE_H
#define HASHTABLE_H
#include"Node.h"
#include <iostream>
using namespace std;

//Класс словаря, основанный на хэш-таблице.
class Dictionary {
private:
	//Минимальная вместимость словаря.
	const int MinCapacity = 5;

	//Фактор рсота для словаря.
	int _growthFactor = 2;

	//Вместимость словаря.
	int _capacity;

	//Размер текущего словаря.
	int _size;

	//Указатель, на массив указателей значений текущего словаря.
	Node** _dictionary;

	//Проверяет, если у элементов одинаковые ключи, то приравнивает value перевого элемента value второго элемента.
	bool CompareKeys(Node* nodeFirst,Node* nodeSecond);

	//Создает новый словарь с новой вместимостью. Переуказывает указатель на новый словарь.
	void CreateNewHashTable(int capacity);

	//Изменяет вместимость словаря, создавая новый словаря.
	void ResizeHashTable();

public:

	//Конструктор по умолчанию.
	Dictionary();

	//Получить текущий словарь.
	Node** GetHashTable();

	//Получить текущий размер словаря.
	int GetSize();

	//Получить вместимость текущего словаря.
	int GetCapacity();

	//Добавить элемент в словарь.
	void Put(string key, int data);

	//Простая хеш-функция.
	int Hash(string key);

	//Хеш-функция Пирсона. Возвращает хеш, учитывая вместимость словаря.
	unsigned int PearsonHash(string key, int capacity);

	//Ищет значение по ключу. Возврщает значение элемента.
	int SearchingValue(string key);

	//Удаляем элемент по ключу.
	void DeleteElement(string key);
};
#endif