#include <iostream>

//����, �������� �������� � ��������� �� ��������� � ��������� ��������.
struct Node {
public:

	//�������� ������. � ����� ������ �����.
	int Data;

	//��������� �� ��������� ������� ������.
	struct Node* Next;

	//��������� �� ���������� ������� ������.
	struct Node* Prev;

	//����������� ��� ������������� ���� � �������� ���������.
	Node() {
		this->Data = -1;
		this->Next = nullptr;
		this->Prev = nullptr;
	}

	//����������� ��� ������������� ���� � �������� ���������.
	Node(int Data)
	{
		this->Data = Data;
		this->Next = nullptr;
		this->Prev = nullptr;
	}
};