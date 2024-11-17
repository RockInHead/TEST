#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iostream>

struct DynamicArray {
	int Capacity, Length;
	int* currentArray;
	DynamicArray();
	void ExpandArray();
	void ReduceArray();
	void AddElement(int array[], int newElement);
	void AddElmentStart(int array[], int newElement);
	void Insert(int array[], int newElement, int indexOfElement);
	void DeleteElementIndex(int array[], int indexOfElement);
	void DeleteElementValue(int array[], int DeletedElement);
	int LinearSearch(int array[], int seacrhingElement);
	void MergeSort(int array[]);
	void MergeSortHelper(int array[], int left, int right);
	void Merge(int array[], int left, int mid, int right);
	int BinarySearch(int array[], int target);

	
};
#endif // DYNAMIC_ARRAY_H