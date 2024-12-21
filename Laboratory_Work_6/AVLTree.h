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

	void InitializeTree(AVLTree*& tree);

	size_t GetHeight(AVLNode* treeNode);

	int GetBalanceFactor(AVLNode* treeNode);

	void FixHeight(AVLNode* treeNode);

	AVLNode* RotateLeft(AVLNode* treeNode);

	AVLNode* RotateRight(AVLNode* treeNode);

	AVLNode* Balance(AVLNode* treeNode);

	AVLNode* Insert(AVLNode* treeNode, int key);

	AVLNode* FindMinimal(AVLNode* treeNode);

	AVLNode* RemoveMinimal(AVLNode* treeNode);

	AVLNode* Remove(AVLNode* treeNode, int key);

	AVLNode* FindNode(AVLNode* node, int key);

	void FreeTree(AVLNode* treeNode);

	int CalculateHeight(AVLNode* node);

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