#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "AVLNode.h"
class AVLTree {
private:
	//Указатель на корень дерева.
	AVLNode* _root;

	//Количество элементов в дереве.
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
	//Возврщает количество элементов в дереве.
	int GetSize();

	//Возвращает высоту дерева.
	int GetHeight();

	//Возвращает текущий корень дерева.
	AVLNode* GetRoot();

	//Конструктор по умолчанию.
	AVLTree();

	//Добавление элемента в дерево.
	void AddElement(int data);

	//Удаление элемента по значению.
	void DeleteElement(int data);

	//Возврщает минимальный элемент дерева.
	int FindMin();

	//Возвращает максимальный элемент дерева.
	int FindMax();

	int FindValue(int data);
};
#endif