#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include "RBNode.h"
class RBTree {
private:
	//Указатель на корень дерева.
	RBNode* _root;
	
	//Количество элементов в дереве.
	int _size;

	void InsertValue(RBNode*& root, const int value);

	RBNode* InsertNode(RBNode*& root, RBNode*& node);

	void FixInsertRBTree( RBNode*& node);

	Color GetColor(RBNode* node);

	void SetColor(RBNode*& node, const Color color);

	void RotateLeft(RBNode*& root, RBNode*& node);

	void RotateRight(RBNode*& root, RBNode*& node);
	////Инициализиурет корень дерева.
	//void InitRoot(int data);

	////Функция вставки элемента дерева.
	//void Insert(Node*& node, int data);

	////Вычисляет текущую высоту дерева.
	//int CalculateHeight(Node* node);

	////Удаляет элемент дерева.
	//void DeleteNode(Node*& node, int data);

public:
	//Возврщает количество элементов в дереве.
	int GetSize();

	//Возвращает высоту дерева.
	int GetHeight();

	//Возвращает текущий корень дерева.
	RBNode* GetRoot();

	//Конструктор по умолчанию.
	RBTree();

	//Добавление элемента в дерево.
	void AddElement(int data);

	//Удаление элемента по значению.
	void DeleteElement(int data);

	//Возврщает минимальный элемент дерева.
	int FindMin();

	//Возвращает максимальный элемент дерева.
	int FindMax();

};
#endif
