#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include "AVLNode.h"

class AVLTree {
private:
	int _rotationCount; // ������� ��� ���������


	//��������� �� ������ ������.
	AVLNode* _root;

	//���������� ��������� � ������.
	int _size;

	//��������� ������� ������ ������.
	int CalculateHeight(AVLNode* node);

	//������� ������ ����� � ������. ���� ������ ���������� ������������������ ����� �������, ����������� ������������.
	AVLNode* Insert(AVLNode* treeNode, int key);

	// ��������� ������ ������� ���� � ��������� �������� ��� �������������.
	AVLNode* Balance(AVLNode* treeNode);

	//��������� ������ ����. ������ - ������������ ������ ��� ����������� + 1.
	void FixHeight(AVLNode* treeNode);

	//���������� ������ ��� ��������.
	int GetHeight(AVLNode* treeNode);

	// ��������� ������ �������, �� ���� ������� ����� ������� ������ � ������� �����������.
	int GetBalanceFactor(AVLNode* treeNode);

	//������ ������� ��� ����.
	AVLNode* RotateRight(AVLNode* treeNode);

	//����� ������� ��� ����.
	AVLNode* RotateLeft(AVLNode* treeNode);

	//������� ���� � �������� ������ � ��������� ������������ ��� �������������.
	AVLNode* Remove(AVLNode* treeNode, int key);

	//������� ������������ ���� � ���������.
	AVLNode* FindMinimal(AVLNode* treeNode);

	//������� ����������� ���� � ��������� � ������ ������������.
	AVLNode* RemoveMinimal(AVLNode* treeNode);

	//���������� ��������� �� ��������� ���� ��� nullptr, ���� ���� �� ������.
	AVLNode* FindNode(AVLNode* node, int key);

	//������� ��� ����� � node.
	void FreeTree(AVLNode*& node);

public:

	//���������� ������ ������.
	int GetTreeHeight();

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

	//���������� �������� �������� ��������.
	int FindValue(int data);

	//������� �� ������.
	void ClearTree();

	int GetRotationCount();
};
#endif