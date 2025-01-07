#include"Node.h"
#include <iostream>

//����� ������������� ������.
class List {
private:

	//������ �������� ������
	int _size;

	//��������� �� ������ ������.
	Node* _head;

	//��������� �� ����� ������.
	Node* _tail;

	//�������������� ������ ������.
	void InitRoot(int Data);

	//������������� ������ �� ��������� ������� ������. ������� ������ �������.
	void DeleteHead();

	//������������� ����� �� ���������� ������� ������. ������� ����� �������.
	void DeleteTail();

	//������ ������� ��� �������� �������� ������.
	void SwapNodes(Node* firstNode, Node* secondNode);

public:
	//����������� �� ��������� ��� ������
	List();

	//������� ������������, ������� ������.
	int GetHead();

	//������� ������������, ������� �����.
	int GetTail();

	//���������� ������ �������� ������.
	int GetSize();

	//���������� ������� ������
	int* GetList();

	//������� ���������� �������� � ����� �������.
	void AddNodeAtEnd(int Data);

	//������� ���������� �������� � ������ �������.
	void AddNodeAtStart(int Data);

	//������� �������� �������� �� �������.
	void DeleteNodeIndex(int Data);

	//��������� ������� � ������ ����� ������������ ���������
	void InsertBefore(int Data, int indexOfElement);

	//��������� ������� � ������ ����� ������������� ��������
	void InsertAfter(int Data, int indexOfElement);

	// ������� ��������� ������ �������� � ������
	int LinearSearch(int seacrhingElement);

	//��������� ������ �� �����������.
	void SortList();

};
