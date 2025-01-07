#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iostream>

//Класс динамического массива.
class DynamicArray {
private:
	//Вместимость в масссив.
	int _capacity;

	//Длина массива.
	int _length; 

	//Фактор роста, в какое количиство раз будет увеличиваться массив.
	int _growthFactor;

	//Минимальная вместимость массива.
	int const MinCapacity=4;

	//Указатель на текущий массив.
	int* _currentArray;

	//Создает новый массива с новой вместимостью. 
	//Переуказывает указатель на новый созданный массив.
	void CreateNewArray(int capacity);

	//Вспомогательная функция для сортировки массива.
	void MergeSortHelper(int left, int right);

	//Функция объединения массивов
	void Merge(int left, int mid, int right);

public:

	//Возвращает размер массива.
	int GetLength();

	//Возвращает вместимость массива.
	int GetCapacity();

	//Возвращает массив.
	int* GetArray();

	//Констуктор по умолчанию массива
	DynamicArray();

	//Изменяет размер массива, создавая новый массив
	void ResizeArray();

	// Функция добавления элемента в конец массива
	void AddElement(int newElement);

	// Функция вставки элемента вначало
	void AddElmentStart(int newElement);

	// Функция вставки элемента по индексу
	void Insert(int newElement, int indexOfElement);

	// Функция удаления элемента по индексу
	void DeleteElementIndex(int indexOfElement);

	// Функция удаления элемента по значению
	void DeleteElementValue(int DeletedElement);

	// Функция линейного поиска элемента в массиве
	int LinearSearch(int seacrhingElement);

	//Сортировка массива с помощью MergeSort
	void MergeSort();

	// Функция бинарного поиска
	int BinarySearch(int target);
};
#endif 