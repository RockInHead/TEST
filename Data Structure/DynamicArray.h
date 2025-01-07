#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iostream>

//����� ������������� �������.
class DynamicArray {
private:
	//����������� � �������.
	int _capacity;

	//����� �������.
	int _length; 

	//������ �����, � ����� ���������� ��� ����� ������������� ������.
	int _growthFactor;

	//����������� ����������� �������.
	int const MinCapacity=4;

	//��������� �� ������� ������.
	int* _currentArray;

	//������� ����� ������� � ����� ������������. 
	//������������� ��������� �� ����� ��������� ������.
	void CreateNewArray(int capacity);

	//��������������� ������� ��� ���������� �������.
	void MergeSortHelper(int left, int right);

	//������� ����������� ��������
	void Merge(int left, int mid, int right);

public:

	//���������� ������ �������.
	int GetLength();

	//���������� ����������� �������.
	int GetCapacity();

	//���������� ������.
	int* GetArray();

	//���������� �� ��������� �������
	DynamicArray();

	//�������� ������ �������, �������� ����� ������
	void ResizeArray();

	// ������� ���������� �������� � ����� �������
	void AddElement(int newElement);

	// ������� ������� �������� �������
	void AddElmentStart(int newElement);

	// ������� ������� �������� �� �������
	void Insert(int newElement, int indexOfElement);

	// ������� �������� �������� �� �������
	void DeleteElementIndex(int indexOfElement);

	// ������� �������� �������� �� ��������
	void DeleteElementValue(int DeletedElement);

	// ������� ��������� ������ �������� � �������
	int LinearSearch(int seacrhingElement);

	//���������� ������� � ������� MergeSort
	void MergeSort();

	// ������� ��������� ������
	int BinarySearch(int target);
};
#endif 