#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include "RBNode.h"
class RBTree {
private:
	//��������� �� ������ ������.
	RBNode* _root;
	
	//���������� ��������� � ������.
	int _size;

	// ��������� ����� ���� �� ����� root. ���������� ����� ������.
	RBNode* InsertNode(RBNode*& root, RBNode*& node);

	//���������� �������� ������ ����� ������� ��������. ��������� �������� � ���������� ����� ��� �������������� ���������� ��������� ������.
	void FixInsertRBTree( RBNode*& node);

	// ���������� ���� ����. ���� ���� ����� nullptr, ���������� ������ ����.
	Color GetColor(RBNode* node);

	// ������������� ���� ���� ������. ���� ���� ����� nullptr, �������� ������������.
	void SetColor(RBNode*& node, const Color color);

	// ������������ ��������� ������ ������ ��������� ����. ���� �������� ���� ����� ���������� ������� �������.
	void RotateLeft(RBNode*& root, RBNode*& node);

	// ������������ ��������� ������� ������ ��������� ����. ���� �������� ���� ����� ���������� ������ �������.
	void RotateRight(RBNode*& root, RBNode*& node);

	// ���� ���� �� �������� � ������� ��� �� ������. ���������� ��������� �� ��������� ����.
	RBNode* DeleteNode(RBNode*& root, int data);

	// ������� ���� � ����������� ��������� � ���������. ���������� ��������� �� ���� ����.
	RBNode* MinValueNode(RBNode*& node);

	// ���������� �������� ������ ����� �������� ����, ������� �������������� ������.
	void FixDeleteRBTree(RBNode*& root, RBNode*& node);

	// ������������ ������ 1 �������� ���� � ������.
	// ������� ������ ������, ���� �� ����������, ��� ���������� 1, ���� ���� �������.
	inline int DeleteCase1(RBNode*& root, RBNode*& node);

	// ������������ ������ 2 �������� ���� � ������.
	// ������� ����, ������� ����� ������ ��� �� ������ �������, �������� ����������� ������� � ��������� ���������� ����.
	inline void DeleteCase2(RBNode*& root, RBNode*& node);

	// ������������ ������ 3 �������� ���� � �����-������� ������.
	// ����� ���� ���� �������� �������. ���������� 1, ���� ���� ��� �����, ����� 0.
	inline int DeleteCase3(RBNode*& root, RBNode*& sibling, RBNode*& parent, RBNode*& pointer);

	// ������������ ������ 4 �������� ���� � ������.
	// ����� ���� ���� �������� ������, �� � ���� ���� ���� �� ���� ������� �������.
	inline int DeleteCase4(RBNode*& root, RBNode*& sibling, RBNode*& parent, RBNode*& pointer);

	//���������� ��������� �� ��������� ���� ��� nullptr, ���� ���� �� ������.
	RBNode* FindNode(RBNode* node, const int data);

	//��������� ������� ������ ������.
	int CalculateHeight(RBNode* node);

	//������� ��� ����� � node.
	void FreeTree(RBNode*& node);

public:
	//���������� ������ ������.
	int GetHeight();

	//���������� ������� ������ ������.
	RBNode* GetRoot();

	//����������� �� ���������.
	RBTree();

	//���������� �������� � ������.
	void AddElement(int data);

	//�������� �������� �� ��������.
	void DeleteElement(int data);

	//��������� ����������� ������� ������.
	int FindMin();

	//���������� ������������ ������� ������.
	int FindMax();

	//���������� �������� �������� ��������.
	int FindValue(int data);

	//������� �� ������.
	void ClearTree();
};
#endif
