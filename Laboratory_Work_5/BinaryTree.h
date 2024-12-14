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

	void Insert(Node* node, int data);
public:

	//Возвращает текущее бинарное дерево.
	Node* GetBinaryTree();

	//Конструктор по умолчанию.
	BinaryTree();
	
	//Добавление элемента в дерево.
	void AddElement(int data);

	//Удаление элемента по значению.
	void DeleteElement();
};
#endif
