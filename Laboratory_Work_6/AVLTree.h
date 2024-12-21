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