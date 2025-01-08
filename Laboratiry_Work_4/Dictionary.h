#ifndef HASHTABLE_H
#define HASHTABLE_H
#include"Node.h"
#include <iostream>
using namespace std;

//����� �������, ���������� �� ���-�������.
class Dictionary {
private:
	//����������� ����������� �������.
	const int MinCapacity = 5;

	//������ ����� ��� �������.
	int _growthFactor = 2;

	//����������� �������.
	int _capacity;

	//������ �������� �������.
	int _size;

	//���������, �� ������ ���������� �������� �������� �������.
	Node** _dictionary;

	//���������, ���� � ��������� ���������� �����, �� ������������ value �������� �������� value ������� ��������.
	bool CompareKeys(Node* nodeFirst,Node* nodeSecond);

	//������� ����� ������� � ����� ������������. ������������� ��������� �� ����� �������.
	void CreateNewHashTable(int capacity);

	//�������� ����������� �������, �������� ����� �������.
	void ResizeHashTable();

public:

	//����������� �� ���������.
	Dictionary();

	//�������� ������� �������.
	Node** GetHashTable();

	//�������� ������� ������ �������.
	int GetSize();

	//�������� ����������� �������� �������.
	int GetCapacity();

	//�������� ������� � �������.
	void Put(string key, int data);

	//������� ���-�������.
	int Hash(string key);

	//���-������� �������. ���������� ���, �������� ����������� �������.
	unsigned int PearsonHash(string key, int capacity);

	//���� �������� �� �����. ��������� �������� ��������.
	int SearchingValue(string key);

	//������� ������� �� �����.
	void DeleteElement(string key);
};
#endif