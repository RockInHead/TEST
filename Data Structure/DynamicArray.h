#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iostream>

struct DynamicArray {
private:
	int _capacity, _length, _growthFactor;;
	int* _currentArray;
public:
	//Возвращает размер массива.
	int GetLength() const;
	//Возвращает вместимость массива.
	int GetCapacity() const;
	//Возвращает массив.
	int* GetArray() const;
	//Констуктор по умолчанию массива
	DynamicArray();
	//Конструктор массива
	/*DynamicArray(int initCapacity, int growthFactor);*/
	// Функция увеличения массива
	void ExpandArray();
	// Функция уменьшения массива
	void ReduceArray();
	// Функция добавления элемента в конец массива
	void AddElement(int array[], int newElement);
	// Функция вставки элемента вначало
	void AddElmentStart(int array[], int newElement);
	// Функция вставки элемента по индексу
	void Insert(int array[], int newElement, int indexOfElement);
	// Функция удаления элемента по индексу
	void DeleteElementIndex(int array[], int indexOfElement);
	// Функция удаления элемента по значению
	void DeleteElementValue(int array[], int DeletedElement);
	// Функция линейного поиска элемента в массиве
	int LinearSearch(int array[], int seacrhingElement);
	//Сортировка массива с помощью MergeSort
	void MergeSort(int array[]);
	//Вспомогательная функция для сортировки массива.
	void MergeSortHelper(int array[], int left, int right);
	//Функция объединения массивов
	void Merge(int array[], int left, int mid, int right);
	// Функция бинарного поиска
	int BinarySearch(int array[], int target);

	
};
#endif // DYNAMIC_ARRAY_H