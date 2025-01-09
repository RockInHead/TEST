#ifndef CARTESIANTREE_H
#define CARTESIANTREE_H
#include <iostream>
#include "CartesianNode.h"

//����� ����������� ������.
class CartesianTree {
private:
	//��������� �� ������ ������.
	CartesianNode* _root;

	//���������� ��������� � ������.
	int _size;

	//�������������� ������ ������.
	void InitRoot(int data);
	
	//������� 2 ������ � 1.
	static CartesianNode* Merge(CartesianNode* a, CartesianNode* b);

	//������� ������ �� �����.
	static void Split(CartesianNode* node, int key, CartesianNode*& a, CartesianNode*& b);

	//������� ������� �������� ������.
	void Insert(CartesianNode*& node, int key, int priority);

	//������� ������� �� �����.
	void Remove(CartesianNode*& node, int key);

	//������� ��� ����� � node.
	void FreeTree(CartesianNode*& node);

public:
	//������� ��� �������� ������.
	void ClearTree();

	//��������� ���������� ��������� � ������.
	int GetSize();

	//���������� ������� ������ ������.
	CartesianNode* GetRoot();

	//����������� �� ���������.
	CartesianTree();

	//���������� �������� � ������.
	void AddElementNotOptimazed(int key);

	//�������� �������� �� ��������.
	void DeleteElementNotOptimazed(int key);

	//���������� �������� � ������.
	void AddElementOptimazed(int key);

	//�������� �������� �� ��������.
	void DeleteElementOptimazed(int key);
};
#endif
