#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "AVLNode.h"
class AVLTree {
private:
	//��������� �� ������ ������.
	AVLNode* _root;

	//���������� ��������� � ������.
	int _size;

public:
	//��������� ���������� ��������� � ������.
	int GetSize();

	//���������� ������ ������.
	int GetHeight();

	//���������� ������� ������ ������.
	AVLNode* GetRoot();

	//����������� �� ���������.
	AVLTree();

	//���������� �������� � ������.
	void AddElement(int data);

	//�������� �������� �� ��������.
	void DeleteElement(int data);

	//��������� ����������� ������� ������.
	int FindMin();

	//���������� ������������ ������� ������.
	int FindMax();

	int FindValue(int data);
};
#endif