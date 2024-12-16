#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "Node.h"
class BinaryTree {
private:
	//Указатель на корень дерева.
	Node* _root;

	//Количество элементов в дереве.
	int _size;

	//Инициализиурет корень дерева.
	void InitRoot(int data);
	
	//Функция вставки элемента дерева.
	void Insert(Node*& node, int data);

	//Вычисляет текущую высоту дерева.
	int CalculateHeight(Node* node);

	//Удаляет элемент дерева.
	void DeleteNode(Node*& node, int data);

public:
	//Возврщает количество элементов в дереве.
	int GetSize();

	//Возвращает высоту дерева.
	int GetHeight();

	//Возвращает текущий корень дерева.
	Node* GetRoot();

	//Конструктор по умолчанию.
	BinaryTree();
	
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
